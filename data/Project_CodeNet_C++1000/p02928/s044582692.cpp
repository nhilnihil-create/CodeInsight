#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k; cin >> n >> k;
	vector<ll>a(n);
	for (int i = 0; i < n; i++)cin >> a.at(i);
	vector<ll>inans(n);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			inans.at(i) = 0;
			break;
		}
		else {
			ll x = a.at(i);
			ll ct = 0;
			for (int j = i + 1; j < n; j++) {
				if (x > a.at(j))ct++;
			}
			inans.at(i) = ct;
		}
	}
	vector<ll>loopans(n);
	for (int i = 0; i < n; i++) {
		ll ct = 0;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			if (a.at(i) > a.at(j))ct++;
		}
		loopans.at(i) = ct;
	}
	ll ans = 0;
	for (int i = 0; i <= n - 1; i++) {
		ans += (ll) k * inans.at(i);
		ans %= 1000000007;
		ans += (ll)((k * (k - 1) / 2) % 1000000007) * (loopans.at(i));
		ans %= 1000000007;
	}
	cout << ans << endl;
}