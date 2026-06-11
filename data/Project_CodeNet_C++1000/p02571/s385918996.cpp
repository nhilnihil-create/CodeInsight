#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	string s, t;
	cin >> s >> t;
	int ans = INT_MAX;
	int i = 0, j = 0, n = s.length(), m = t.length();
	for (int i = 0; i <= n - m; i++) {
		string str = s.substr(i, m);
		int diff = 0;
		for (int j = 0; j < m; j++) {
			if (str[j] != t[j])
				diff++;
		}
		ans = min(diff, ans);
	}
	cout << ans;
	return 0;
}