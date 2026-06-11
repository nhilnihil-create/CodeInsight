#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n;
	string s;
	cin >> n >> s;

	for (auto el : s) {
		int num = el - 'A';
		num += n;
		num %= 26;
		cout << (char)('A' + num);
	}
}