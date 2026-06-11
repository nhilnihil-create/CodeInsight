#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.size(), m = t.size(), res = INT_MAX;
	for (int i = 0; i <= n - m; i++) {
		int cnt = 0;
		for (int j = i; j < i + m; j++) {
			cnt += (s[j] != t[j - i]);
		}
		res = min(res, cnt);
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}