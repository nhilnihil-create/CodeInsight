#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

bool palim(string s) {
	for(int i = 0; i < s.size() / 2; i++) {
		if(s[i] != s[s.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	cin >> s;

	if(!palim(s)) return printf("No\n"), 0;

	s.resize(s.size() / 2);

	if(!palim(s)) return printf("No\n"), 0;

	printf("Yes\n");
}
