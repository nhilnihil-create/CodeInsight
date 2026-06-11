#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int vowel(char c){
	if(65 <= c && c <= 90){
		return (int)c + 32;
	}
	else if(97 <= c && c <= 122){
		return (int)c;
	}
	else{
		return 0;
	}
}

int main(){
	string s;
	int cnt[26];
	for(int i; i < 26; i++){
		cnt[i] = 0;
	}
	while(getline(cin, s) != 0){
		for(int i = 0; i < s.length(); i++){
			int c = vowel(s[i]);
			if(c != 0){
				int n = c - 97;
				cnt[n]++;
			}
		}
	}
	for(int i; i < 26; i++){
		cout << (char)(i + 97) << " : " << cnt[i] << "\n";
	}
}
