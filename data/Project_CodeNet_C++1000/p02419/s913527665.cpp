#include <iostream>
#include <stdio.h>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string word, s;
    int count = 0;
    cin >> word;
    for (int i = 0; i < word.size(); i++) {
        if (isupper(word[i])){
            word[i] = tolower(word[i]);
        }
    }
    while(1) {
        cin >> s;
        if (s == "END_OF_TEXT") {
            cout << count << endl;
            break;
        }
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        if (word == s) {
            count++;
        }
    }
    return 0;
}