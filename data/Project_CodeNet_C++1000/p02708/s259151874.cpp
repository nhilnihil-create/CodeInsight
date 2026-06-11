#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, k; cin >> n >> k;
	ll const mod = 1000000007;
	ll ans = 0;
	for (ll i = k; i <= n + 1; i++) {
		ll ans1 = i * (2 * n - i + 1) / 2;
		ll ans2 = (i - 1) * i / 2;
		ll ans3 = ans1 - ans2 + 1;
		ans = (ans + ans3) % mod;
	}
	cout << ans << endl;
	return 0;
}