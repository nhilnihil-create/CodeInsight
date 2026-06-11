#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ll n, k; cin >> n >> k;
	ll res = 0;
	for (ll i = k; i <= n + 1; i++) {
		ll l = (i - 1) * i / 2;
		ll r = n * i - l;
		res += r - l + 1;
		res %= MOD;
	}
	cout << res << '\n';
	return 0;
}
