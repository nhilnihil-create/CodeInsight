#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> dp(n, vector<int>(n,0));
	for (int i = 0; i < n; ++i) {
		if (s[i] == s[n - 1]) {
			dp[n - 1][i] = 1;
		}
	}

	for (int i = n - 2; 0 <= i; --i) {
		for (int j = 0; j < n - 1; ++j) {
			if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j + 1] + 1;
			}
		}
		if (s[i] == s[n - 1]) {
			dp[i][n - 1] = 1;
		}
	}

	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = min(abs(i - j), dp[i][j]);
			ret = max(ret, dp[i][j]);
		}
	}
	cout << ret << endl;

	return 0;
}