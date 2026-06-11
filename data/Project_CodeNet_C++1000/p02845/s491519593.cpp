#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
using ll = long long;
using namespace std;
const ll mod = 1000000007;
char A[1234][1234];
signed main() {
	ll n, ans = 1; cin >> n; map<ll, ll> m;
	m[0 - 1] = 3;
	rep(i, n) {
		ll a; cin >> a;
		ans *= (m[a - 1] - m[a]); m[a]++; ans %= mod;
	}
	cout << ans << endl;
	return 0;
}