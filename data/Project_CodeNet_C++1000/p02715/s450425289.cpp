#include <bits/stdc++.h>
#define rep(i,n) for(long long i = 0; i < (long long)(n); ++i)

using namespace std;
using ll = long long;

const ll mod = 7 + 1e9;

ll mpow (ll x, ll y) {
	ll a = 1;
	for (int i = 30; i >= 0; i--) {
		a = (a * a) % mod;
		if (y >> i & 1) {
			a = (a * x) % mod;
		}
	}
	return a;
}

int main() {
	ll n, k, ans = 0;
	cin >> n >> k;
	vector<ll> g(k + 1, 0);
	for (ll i = k; i > 0; i--) {
		g[i] = mpow(k / i, n);
		for (int v = 2; v * i <= k; v++) {
			g[i] -= g[v * i];
			if (g[i] < 0) g[i] += mod;
		}
		ans += g[i] * i;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
