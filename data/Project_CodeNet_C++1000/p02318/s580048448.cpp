#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int string_distance(const string s, const string t) {
	const auto n = s.size();
	const auto m = t.size();
	// dp[i][j]: distance between s[0..i-1] and t[0..j-1]
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= m; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = min({ dp[i - 1][j] + 1,dp[i][j - 1] + 1,dp[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1) });
		}
	}
	return dp[n][m];
}

int main() {
	string s, t;
	cin >> s >> t;
	cout << string_distance(s, t) << endl;
	return 0;
}
