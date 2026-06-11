#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<long long, long long>> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a.begin() + 1, a.end(), greater<pair<long long, long long>>());

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < i; ++j) {
			int l = j;
			int r = i - 1 - j;
			dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + abs(l + 1 - a[i].second) * a[i].first);

			r = j;
			l = i - 1 - j;
			dp[l][r + 1] = max(dp[l][r + 1], dp[l][r] + abs(n - r - a[i].second) * a[i].first);
		}
	}

	long long ans = 0;
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, dp[i][n - i]);
	}

	cout << ans;

	return 0;
}
	