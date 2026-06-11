#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);


	ll n;
	cin >> n;
	ll sum1 = 0, sum2 = 0;
	for (ll i = 1; i <= n; i++) {
		sum1 += (i * (i + 1)) / 2;
	}
	//cout << sum1 << endl;
	for (ll i = 0; i < n - 1; i++) {
		ll a, b;
		cin >> a >> b;
		ll u = min(a, b), v = max(a, b);
		sum2 += u * (n - v + 1);
	}
	//cout << sum2 << endl;
	ll ans = (sum1 - sum2);
	cout << ans << endl;
	return 0;
}