#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	const ll p = 1000005LL;
	vector<ll> num(p, 0);	
	for (ll i = 0; i < n; i++) {
		ll now = a[i];
		if (num[now] != 0) {
			num[now] = 2;
			continue;
		}
		for (ll j = now; j < p; j += now) {
			num[j]++;
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (num[a[i]] == 1) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}