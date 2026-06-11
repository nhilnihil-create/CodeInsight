#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i)cin >> a[i];
	ll ans = 0;
	for (ll bit = 0; bit < 60; ++bit) {
		ll zero = 0;
		ll one = 0;
		for (ll i = 0; i < n; ++i) {
			if ((1ll << bit) & a[i]) ++one;
			else ++zero;
		}
		ll preans = 1;
		for (ll j = 0; j < bit; ++j) {
			preans *= 2;
			preans %= mod;
		}
		preans *= (zero * one) % mod;
		preans %= mod;
		ans = (ans + preans) % mod;

	}
	cout << ans << endl;
}
