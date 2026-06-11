#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; ++i)cin >> v[i];
	ll ans = 1e10;
	for (ll x = 1; x <= 100; ++x) {
		ll sum = 0;
		for (ll i = 0; i < n; ++i) {
			sum += (v[i] - x) * (v[i] - x);
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}
