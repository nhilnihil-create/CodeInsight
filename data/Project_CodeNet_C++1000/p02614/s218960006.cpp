#include <bits/stdc++.h>

#define I_AM_SPEED ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
#define double long double

int32_t main() {
	I_AM_SPEED
	int n, m;
	cin >> n >> m;
	int k;
	cin >> k;
	vector<string> a(n);
	ll ans = 0;
	for (auto &x : a)cin >> x;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < (1 << m); j++) {
			int c = 0;
			for (int x = 0; x < n; x++) {
				for (int y = 0; y < m; y++) {
					if (!((1 << x) & i) && !((1 << y) & j)) {
						c += (a[x][y] == '#');
					}
				}
			}
			if (c == k) {
				ans += (ll)1;
			}
		}
	}
	cout << ans << endl;
}