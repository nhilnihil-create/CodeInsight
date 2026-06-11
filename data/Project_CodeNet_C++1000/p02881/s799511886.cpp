#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	ll ans = 9223372036854775807LL;
	for (ll i = 1; i * i <= n; i++) {
		if ((double)n / i == floor((double)n / i)) {
			ans = min(ans, i + n / i - 2);
		}
	}
	cout << ans << endl;
	return 0;
}