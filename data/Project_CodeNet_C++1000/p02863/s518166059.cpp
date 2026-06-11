#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	int n, t;
	cin >> n >> t;
	vector<vector<int>> dp(n + 1, vector<int>(t + 1, -1e9));
	dp[0][0] = 0;
	vector<pair<int, int>> a(n + 1, {0, 0});
	for (int i = 1; i <= n; ++i){
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; ++i){
		int time = a[i].first, del = a[i].second;
		for (int j = 0; j <= t; ++j){
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j != t) dp[i][min(t, j + time)] = max(dp[i][min(t, j + time)], dp[i - 1][j] + del);
		}
	}
	int ans = 0;
	for (int i = 0; i <= t; ++i){
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}

