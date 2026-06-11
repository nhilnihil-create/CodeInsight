#include<bits/stdc++.h>

using namespace std;
using ll = unsigned long long;
ll MOD = (ll)(1e9 + 7);

ll mult (ll a, ll b) {
	return ((a % MOD) * 1LL * (b % MOD)) % MOD;
}

ll add (ll a, ll b) {	
	b = (b + MOD) % MOD;
	return (a + b) % MOD;
}

ll cc (ll l, ll r, ll x) {
	l = (l / x  + (l % x > 0)) * x;
	if (l > r) {
		return 0;
	}
	return (r - l) / x  + 1;
}


int main () {
	ll k, q;
	cin >> k >> q;
	ll ar[k];
	for (ll i = 0; i < k; i++) {
		cin >> ar[i];
	}
	for (ll i = 0; i < q; i++) {
		ll n, x, m, c = 0, aa[k];
		ll su = 0;
		cin >> n >> x >> m;
		ll kk = (n - 1) / k, rr = (n - 1) % k;
		for (ll j = 0; j < k; j++) {
			su += ar[j] % m;
			aa[j] = su;
			if (!(ar[j] % m)) {
				c += kk + (j < rr);
			}
		}
		cout << n - 1 - c - cc (x + 1, x +  kk * su + (rr > 0 ) * aa[rr - 1], m) << "\n";
	}
}
