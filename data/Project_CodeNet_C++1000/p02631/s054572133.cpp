#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &el : a) {
		cin >> el;
	}
	vector<int> ans(n, 0);
	for (int b = 0; b < 31; b++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += (a[i] >> b) & 1;
		}
		for (int i = 0; i < n; i++) {
			ans[i] += ((cnt % 2 ^ ((a[i] >> b) & 1)) << b);
		}
	}
	for (auto &el : ans) {
		cout << el << ' ';
	}
}