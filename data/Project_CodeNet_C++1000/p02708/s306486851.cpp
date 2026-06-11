#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ll n, k; cin >> n >> k;
	ll res = 0;
	for (ll i = k; i <= n + 1; i++) {
		ll mini = (i - 1) * i / 2;
		ll maxi = (2 * n - i + 1) * i / 2;
		res += (maxi - mini + 1);
		res %= MOD;
	}
	cout << res << '\n';
	return 0;
}
