#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll freq[1005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	for (int i=1; i<=k; i++) {
		ll x;
		cin >> x;
		for (int j=1; j<=x; j++) {
			ll val;
			cin >> val;
			freq[val]++;
		}
	}
	ll ans = 0;
	for (int i=1; i<=n; i++) {
		if (freq[i] == 0) ans++;
	}
	cout << ans;
	return 0;
}