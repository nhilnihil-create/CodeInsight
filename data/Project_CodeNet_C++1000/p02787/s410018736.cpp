#include <bits/stdc++.h>

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const unsigned int M = 1e9 + 7;

int32_t main() {
	fastio;

	int h, n;
	cin >> h >> n;
	vector<int> dp(h + 1, INT_MAX);
	dp[0] = 0;
	while(n--) {
		int a, b;
		cin >> a >> b;
		for(int i = 0; i <= h; ++i) {
			int j = min(h, i + a);
			dp[j] = min(dp[j], dp[i] + b);
		}
	}
	cout << dp[h];

	return 0;
}
