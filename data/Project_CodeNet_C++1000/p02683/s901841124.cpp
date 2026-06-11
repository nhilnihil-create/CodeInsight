#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1000000007

using namespace std;
using ll = long long;

int main() {
	ll n, m, x, ans = 1e18;
	cin >> n >> m >> x;
	ll c[12][13] = {};
	rep(i,n) rep(j,m + 1) cin >> c[i][j];
	for (int i = 0; i < (1 << 12); i++) {
		ll rez[13] = {};
		rep(b,12) {
			if (i >> b & 1) {
				rep(j,m+1) rez[j] += c[b][j];
			}
		}
		int count = 0;
		rep(j,m) if (rez[j + 1] >= x) count++;
		if (count == m) ans = min (ans, rez[0]);
	}
	if (ans == 1e18) ans = -1;
	cout << ans << endl;
	return 0;
}
