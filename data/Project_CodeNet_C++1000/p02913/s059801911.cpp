#pragma gcc optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	vector<vector<int>> dp(n + 1, vector<int>(n + 1));
	int ans = 0;
	for (int i = 0; i < n; ++i)
	for (int j = i + 1; j < n; ++j)
		ans = max(ans, dp[i + 1][j + 1] = s[i] != s[j] ? 0 : min(j - i, dp[i][j] + 1));
	cout << ans << '\n';
}