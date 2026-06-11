#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n + 1);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll x = 0;
	for (ll i = 1; i <= n; i++) {
		if (i % 2 == 1) x += a[i];
		else x -= a[i];
	}
	cout << x << " ";
	ll prev = x;
	for (ll i = 2; i <= n; i++) {
		ll ans = 2 * a[i - 1] - prev;
		cout << ans << " ";
		prev = ans;
	}
	return 0;
}