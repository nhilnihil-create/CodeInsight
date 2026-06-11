#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	map<ll, ll> mp;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll a; cin >> a;
		ans += mp[i + 1 - a];
		mp[i + 1 + a]++;
	}
	cout << ans << endl;
	return 0;
}