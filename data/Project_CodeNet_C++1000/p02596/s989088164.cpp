#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll k; cin >> k;
	ll a = 7;
	ll ans = -1;
	for (int i = 1; i <= k + 3; i++) {
		if (a % k == 0) {
			ans = i;
			break;
		}
		a = a * 10 + 7;
		a %= k;
	}
	cout << ans << endl;
    return 0;
}