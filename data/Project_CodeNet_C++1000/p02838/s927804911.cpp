#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
const ll MOD = 1000000007;
int main() {
	int n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	vector<ll> v(60);
	rep(i, n) {
		rep(j, 60) {
			if (a[i] >> j & 1LL) v[j]++;
		}
	}
	ll ans = 0;
	rep(i, 60) {
		ll p = (1LL << i) % MOD;
		ans += v[i] * (n - v[i]) % MOD * p % MOD;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}