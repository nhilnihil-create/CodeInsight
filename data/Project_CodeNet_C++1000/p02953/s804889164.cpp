#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> h(n);
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (ll i = n - 1; i >= 1; i--) {
		if (h[i - 1] > h[i]) h[i - 1] -= 1;
	}
	string ans = "Yes";
	for (ll i = 0; i < n - 1; i++) {
		if (h[i] > h[i + 1]) {
			ans = "No";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}