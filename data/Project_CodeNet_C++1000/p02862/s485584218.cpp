#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 670000;
// const ll MAX = 510000;
ll fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		fac[i] = fac[i - 1] * i % MOD;
		inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
		finv[i] = finv[i - 1] * inv[i] % MOD;
	}
}

ll COM(ll n, ll k) {
	if (n < k) return 0;
	if (n < 0 || k < 0) return 0;
	return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
	ll x, y;
	cin >> x >> y;

	COMinit();

	ll ans = 0;
	bool cond1 = ((2*x - y) % 3 == 0);
	bool cond2 = ((2*y - x) % 3 == 0);
	if (cond1 && cond2){
		ll m = (2*x - y) / 3;
		ll n = (2*y - x) / 3;
		ans = COM(m+n, m);
	}

	cout << ans << "\n";

	return 0;
}
