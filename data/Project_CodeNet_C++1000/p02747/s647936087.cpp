#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	string s;
	cin >> s;
	int n = int(s.size());
	if (n % 2 == 1) {
		cout << "No" << '\n';
		exit(0);
	}
	for (int i = 0; i < n; i += 2) {
		if (s[i] == 'h' && s[i+1] == 'i') {
			// good
		} else {
			cout << "No" << '\n';
			exit(0);
		}
	}
	cout << "Yes" << '\n';
}
