#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

const ll mod = 1000000007;
ll inv (ll x) {
	ll a = 1;
	ll m = mod - 2;
	for (ll q = 31; q >= 0; q--) {
		a = a*a;
		a %= mod;
		if (m >> q & 1) a *= x;
		a %= mod;
		}
	return a;
}
int main() {
	ll s;
	cin >> s;
	ll ans = 0;
	if (s < 3) {
		ans = s / 3;
		cout << ans << endl;
		return 0;
	}
	for (ll i = 1; i * 3 <= s; i++) {
		ll n = s - (i * 3);
		ll k = i - 1;
		ll c = 1;
		ll div = 1;
		n += k;
		rep(j, k) {
			c *= n;
			c %= mod;
			n--;
			div *= (j + 1);
			div %= mod;
		}
		c *= inv(div);
		ans += c;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
