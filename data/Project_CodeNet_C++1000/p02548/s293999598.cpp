#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6 + 5, MOD = 1e9 + 7;
const ll INF = 1e18 + 17;

int cnt[N];

void solve() {
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j <= n; j += i) {
			++cnt[j];
		}
		res += cnt[i];
	}
	cout << res;
}

main() {
	ios :: sync_with_stdio(0);		
	cin.tie(0);
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		solve();
		cout << '\n';
	} 
	return 0;
}