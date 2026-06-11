#include <bits/stdc++.h>
#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
// #define mod 1000000007
#define mod 998244353
using namespace std;
ll dp[3001][3001];

int main()
{
	ios::sync_with_stdio(false);
	int n, s;
	cin >> n >> s;
	int a[n + 1];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i + 1];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			dp[i][j] = 2 * dp[i - 1][j];
			if (j - a[i] >= 0)
			{
				dp[i][j] += dp[i - 1][j - a[i]];
			}
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][s] << endl;
	return 0;
}