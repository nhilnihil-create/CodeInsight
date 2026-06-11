#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int dp[200013][13];

signed main () {
	string s; 
	cin >> s;
	int n = s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			for (int j = 0; j < 10; ++j) {
				for (int r = 0; r < 13; ++r) 
					(dp[i + 1][(r * 10 + j) % 13] += dp[i][r]) %= mod;
			}
		}
		else {
			int j = s[i] - '0';
			for (int r = 0; r < 13; ++r)
				(dp[i + 1][(r * 10 + j) % 13] += dp[i][r]) %= mod;
		}
	}
	cout << dp[n][5] << '\n';
}
