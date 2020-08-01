Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Solution:

class Solution {
public:
    bool detectCapitalUse(string word) {
        int word_length=word.length();
        int small=0, capital=0;
        
        for (int i=0;i<word_length;i++){
            if (word[i]>64 && word[i]<91)
                small++;
            if (word[i]>96 && word[i]<123)
                capital++;
       }
        if (small==word_length)
            return true;
        if (capital==word_length)
            return true;
        
        int first;
        if (word[0]>64 && word[0]<91)
            first=1;
        else
            first=0;
        for (int i=1;i<word_length;i++){
            if (first==1 && word[i]>64 && word[i]<91)
                return false;
        }
        for (int i=1;i<word_length;i++){
            if (first==0 && word[i]>64 && word[i]<91)
                return false;
        }
        return true;
    }
};