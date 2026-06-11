#include <iostream>
#include <cstdio>
using namespace std;

string s;
int main() {
	cin >> s;
	for(int i=0; s[i]; i++) {
		putchar(s[i]=='?' ? 'D' : s[i]);
	}
	return 0;
}
