#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	string s;
	cin >> s;

	reverse(s.begin(), s.end());
	int n = s.size();
	vector<vector<int>> dp(n, vector<int>(2, 0));
	dp[0][0] = s[0] - '0';
	dp[0][1] = 11 - (s[0] - '0');
	for (int i = 1; i < n; ++i) {
		int x = s[i] - '0';
		dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + x;
		dp[i][1] = min(dp[i-1][0] + (11 - x), dp[i-1][1] + (9-x));
	}
	cout << min(dp[n-1][0], dp[n-1][1]) << endl;

	return 0;
}
