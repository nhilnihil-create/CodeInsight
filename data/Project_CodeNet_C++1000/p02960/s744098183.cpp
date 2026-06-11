#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long dp[100000][13];
int main() {
	string s;
	cin >> s;
	int n = s.size();
	if (s[n - 1] == '?') {
		for (int j = 0; j < 10; j++) {
			dp[n - 1][j] = 1;
		}
	}
	else {
		dp[n - 1][s[n - 1] - '0'] = 1;
	}
	int pw = 10;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] != '?') {
			int val = pw * (s[i] - '0');
			for (int j = 0; j < 13; j++) {
				dp[i][j] += dp[i + 1][(j - val % 13 + 13) % 13];
				dp[i][j] %= mod;
			}
		}
		else {
			for (int dig = 0; dig < 10; dig++) {
				int val = dig * pw;
				for (int j = 0; j < 13; j++) {
					dp[i][j] += dp[i + 1][(j - val % 13 + 13) % 13];
					dp[i][j] %= mod;
				}
			}
		}
		pw *= 10;
		pw %= 13;
	}
	cout << dp[0][5];
	return 0;
}
