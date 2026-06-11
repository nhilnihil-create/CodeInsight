#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector<vector<long long>> dp(s.length(), vector<long long>(13));
	if (s[0] == '?') {
		for (int j = 0; j < 10; j++) {
			dp[0][j] = 1;
		}
	} else {
		dp[0][s[0] - '0'] = 1;
	}

	int mod = 1000000007;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == '?') {
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k < 10; k++) {
					dp[i][(j * 10 + k) % 13] += dp[i - 1][j];
					dp[i][(j * 10 + k) % 13] %= mod;
				}
			}
		} else {
			for (int j = 0; j < 13; j++) {
				dp[i][(j * 10 + (s[i] - '0')) % 13] += dp[i - 1][j];
				dp[i][(j * 10 + (s[i] - '0')) % 13] %= mod;
			}
		}
	}
	cout << dp[s.length() - 1][5] << endl;

	return 0;
}