#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int num[26];

int main()
{
		int i, alph;
		char c;
		string s, str;
		while (1) {
				getline(cin, str);
				if (str[str.size()-1]=='\0') break;
				else s+=str;
		}
		for (i=0; i<s.size(); i++) {
				c = tolower(s[i]);
				if (isalpha(c)) num[(int)c-97]++;
		}
		for (i=0; i<26; i++) {
				alph = i+97;
				cout << (char)alph << " : " << num[i] << "\n";
		}
}