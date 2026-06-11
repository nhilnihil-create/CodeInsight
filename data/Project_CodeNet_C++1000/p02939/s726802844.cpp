#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main() {
	string s; cin >> s;
	if (s.length() == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<vector<int>> dp(s.length(), vector<int>(2, 0));
	dp[0][0] = 1;
	dp[1][1] = 1;
	if (s[0] != s[1])
		dp[1][0] = 2;
	for (int i = 2; i < s.length(); ++i) {
		// dp[i][0]
		if (s[i] != s[i - 1])
			dp[i][0] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
		else dp[i][0] = dp[i - 1][1] + 1;
		// dp[i][1]
		if (i > 2 && s.substr(i - 3, 2) != s.substr(i - 1, 2))
			dp[i][1] = max(dp[i - 2][1] + 1, dp[i - 2][0] + 1);
		else dp[i][1] = dp[i - 2][0] + 1;
	}
	/*
	for (int i = 0; i < s.length(); ++i)
		cout << dp[i][0] << " ";
	cout << endl;
	for (int i = 0; i < s.length(); ++i)
		cout << dp[i][1] << " ";
	cout << endl;
	*/
	cout << max(dp[s.length() - 1][0], dp[s.length() - 1][1]) << endl;
	return 0;
}