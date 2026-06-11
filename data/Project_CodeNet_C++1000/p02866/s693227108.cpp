#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

ll MOD = 998244353;

long long modpow(long long a, long long n, long long mod) {
	long long res = 1;
	while (n > 0) {
		if (n & 1) res = res * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N; cin >> N;
	vector<ll> D(N);
	rep(i, N) cin >> D[i];
	map<ll, ll> mp;
	rep(i, N) {
		ll d = D[i];
		mp[d] += 1;
	}
	if (mp[0] != 1 || D[0] != 0) {
		cout << 0 << endl;
	} else {
		ll ans = 1;
		for(const auto& m: mp) {
			// cout << m.first << endl;
			if (m.first < 1) continue;
			ans *= modpow(mp[m.first-1ll], m.second, MOD);
			ans %= MOD;
		}
		cout << ans % MOD << endl;
	}
}
