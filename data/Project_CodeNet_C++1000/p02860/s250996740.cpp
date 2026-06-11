#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	string s; cin >> s;
	if (n % 2) {
		cout << "No\n";
		return 0;
	}
	else {
		int h = n / 2;
		for (int i = 0; i < h; i++) {
			if (s[i] != s[h + i]) {
				cout << "No\n";
				return 0;
			}
		}
		cout << "Yes\n";
	}
}
