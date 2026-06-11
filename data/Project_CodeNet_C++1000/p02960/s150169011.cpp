#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
#define V vector<ll>
#define VV vector<V>

const int mod = 1e9 + 7;
signed main(void)
{
	string s;
	ll n, m;
	cin >> s;
	n = s.size();
	VV dp(n + 1, V(13, 0));
	dp[n][0] = 1;
	m = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == '?')
		{
			// '?' = j (0-9) 
			rep(j, 10)
			{
				rep(k, 13)
				{
					dp[i][(j * m + k) % 13] += dp[i + 1][k];
					dp[i][(j * m + k) % 13] %= mod;
				}
			}
		}
		else
		{
			int j = s[i] - '0';
			rep(k, 13)
			{
				dp[i][(j * m + k) % 13] += dp[i + 1][k];
				dp[i][(j * m + k) % 13] %= mod;
			}
		}
		m *= 10;
		m %= 13;
	}
	cout << dp[0][5] << endl;
	return 0;
}
