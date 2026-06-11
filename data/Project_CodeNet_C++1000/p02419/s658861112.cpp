#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

string toLowerString(std::string s) {
     for (int i = 0; i < s.size(); i++) {
         s[i] = tolower(s[i]);
     }

     return s;
}

int main() {
     string w, word;
     int count;

     cin >> w;
     w = toLowerString(w);

     while(true) {
         cin >> word;
         if (word == "END_OF_TEXT") {
             break;
         }
         if (toLowerString(word) == w) {
             count++;
         }
     }

     cout << count << endl;
}