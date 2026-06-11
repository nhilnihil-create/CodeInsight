#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll h, n; cin >> h >> n;
	string ans = "No";
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		h -= a;
		if (h <= 0) {
			ans = "Yes";
			break;
		}
	}
	cout << ans << endl;
    return 0;
}