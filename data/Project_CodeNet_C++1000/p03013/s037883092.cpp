#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	const ll mod = 1000000007;
	int n, m; cin >> n >> m;
	vector<int> broken(n + 2, false);
	for (int i = 1; i <= m; i++) {
		int a; cin >> a;
		broken[a] = true;
	}	
	vector<ll> dp(n + 2, 0);
	dp[0] = 1;
	if (!broken[1]) dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!broken[i]) {
			dp[i] += dp[i - 1] + dp[i - 2];
			dp[i] %= mod;
		}
	}
	cout << dp[n] << endl;
	return 0;
}