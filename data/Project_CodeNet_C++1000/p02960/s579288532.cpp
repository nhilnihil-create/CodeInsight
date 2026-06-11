/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int n = s.length();
	vector<vector<lli> > dp(n + 1, vector<lli>(13, 0ll));
	dp[0][0] = 1ll;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 13; ++j)
		{
			if (s[i] == '?')
			{
				for (int k = 0; k < 10; ++k)
				{
					dp[i + 1][(j * 10 + k) % 13] = (dp[i][j] + dp[i + 1][(j * 10 + k) % 13]) % MOD;
					if (dp[i + 1][(j * 10 + k) % 13] < 0ll)
						dp[i + 1][(j * 10 + k) % 13] += MOD;
				}
			}
			else
			{
				dp[i + 1][(j * 10 + (int)(s[i] - '0')) % 13] = (dp[i][j] + dp[i + 1][(j * 10 + (int)(s[i] - '0')) % 13]) % MOD;
				if (dp[i + 1][(j * 10 + (int)(s[i] - '0')) % 13] < 0ll)
					dp[i + 1][(j * 10 + (int)(s[i] - '0')) % 13] += MOD;
			}
		}
	cout << dp[n][5] << endl;
}