#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll l, r; cin >> l >> r;
	const ll mod = 2019;
	ll ans = 10000;
	for (ll x = l; x <= min(l + 2030LL, r - 1) ; x++) {
		for (ll y = x + 1; y <= min(x + 10000LL, r); y++) {
			ans = min(ans, (x * y) % mod);
		}
	}
	cout << ans << endl;
	return 0;
}