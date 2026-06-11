#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include<cctype>
using namespace std;

int main()
{
	char ch;
	int cnt[26] = {};
	while (scanf("%c",&ch)!=EOF) {
		ch = tolower(ch);
		if (isalpha(ch)) {
			cnt[ch - 'a']++;
		}
		
	}
	
	for (int i = 0; i < 26; i++) {
		printf("%c : %d\n", i + 'a', cnt[i]);
	}


	return 0;
}