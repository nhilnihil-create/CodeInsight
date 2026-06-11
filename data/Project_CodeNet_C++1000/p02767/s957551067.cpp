#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> x(n);
	for (ll i = 0; i < n; i++) {
		cin >> x[i];
	}
	ll ans = 1000000000;
	for (ll j = -100; j <= 100; j++) {
		ll d = 0;
		for (ll i = 0; i < n; i++) {
			d += (j - x[i]) * (j - x[i]);
		}
		ans = min(ans, d);
	}
	cout << ans << endl;
    return 0;
}