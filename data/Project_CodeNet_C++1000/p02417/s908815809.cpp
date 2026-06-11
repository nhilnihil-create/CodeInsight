#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main() {
	char ch,x;
	int ans,  num, counter[100] = {}, i, j;
	while(cin >> ch) {
		if (ch>='A' && ch<='Z') {
			ch += 'a' - 'A';
		}
		num = ch - 'a';
		counter[num]++;
	}
	for (i = 0; i < 26; i++) {
		x = i + 'a';
		ans = counter[i];
		cout << x << " : " << ans << endl;
	}
	return 0;
}