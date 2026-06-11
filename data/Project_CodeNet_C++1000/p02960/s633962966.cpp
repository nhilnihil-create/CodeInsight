#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int64_t n = s.size(), mod = 1000000007;

	vector<vector<int64_t>> dp(n + 1, vector<int64_t>(13, 0));
	dp[0][0] = 1;

	for (int64_t i = 0; i < n; i++)
	{
		for (int64_t j = 0; j < 13; j++)
		{
			if (s[i] == '?')
			{
				for (int64_t d = 0; d <= 9; d++)
				{
					(dp[i + 1][(10 * j + d) % 13] += dp[i][j]) %= mod;
				}
			}
			else
			{
				(dp[i + 1][(10 * j + (s[i] - '0')) % 13] += dp[i][j]) %= mod;
			}
		}
	}

	cout << dp[n][5] << endl;

	return 0;
}