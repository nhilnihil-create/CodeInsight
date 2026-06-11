#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
ll ok[12345678];
signed main() {
	ll n, a, ans = 1; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> a;
		if (a == 0) { ans *= (3 - ok[0]); ok[0]++; ans %= mod; }
		else { ans *= (ok[a - 1] - ok[a]); ok[a]++; ans %= mod; }
	}
	cout << ans << endl;
	return 0;
}