#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

#define dbg(a) cout << "-> " << __LINE__ << ": " << #a << " = " << a << endl

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for (char &c : s) {
		--c;
	}
	int sub = n - 1, odd = s[0] - '0';
	while (sub > 0) {
		odd += (s[sub] - '0');
		odd %= 2;
		sub = (sub - 1) & (n - 1);
	}
	if (odd != 0) {
		cout << 1 << '\n';
		return 0;
	}
	for (char &c : s) {
		if (c == '1') {
			cout << '0' << endl;
			return 0;
		}
		c = (c == '2') ? '1' : '0';
	}
	sub = n - 1, odd = s[0] - '0';
	while (sub > 0) {
		odd += (s[sub] - '0');
		odd %= 2;
		sub = (sub - 1) & (n - 1);
	}
	if (odd != 0) {
		cout << 2 << '\n';
	}
	else {
		cout << 0 << '\n';
	}
	return 0;
}
