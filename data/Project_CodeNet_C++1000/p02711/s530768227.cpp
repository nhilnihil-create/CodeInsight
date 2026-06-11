#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c == '7') {
			puts("Yes");
			return 0;
		}
	}
	puts("No");

	return 0;
}