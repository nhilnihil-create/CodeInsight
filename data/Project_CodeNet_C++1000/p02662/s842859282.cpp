#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fast_io() ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int N = 3e3 + 7;
const int MOD = 998244353;
int n, s;
int dp[N][N];
int a[N];
int binpow(int a, int b)
{
	a %= MOD;
	int res = 1;
	while (b)
	{
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int add(int x, int y)
{
	int res = ((x % MOD) + (y % MOD)) % MOD;
	return res;
}
int mul(int x, int y)
{
	int res = ((x % MOD) * (y % MOD)) % MOD;
	return res;
}
int32_t main() {
	fast_io();
	cin >> n >> s;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
			dp[i][j] = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[0][0] = binpow(2LL, n);
	int inv2 = binpow(2LL, MOD - 2);
	// for (int i = 1; i <= n; i++)
	// 	dp[i][a[i]] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			dp[i][j] = add(dp[i][j], dp[i - 1][j]);
			if (j >= a[i])
			{
				dp[i][j] = add(dp[i][j], mul(dp[i - 1][j - a[i]], inv2));
			}
		}
	}
	cout << dp[n][s] << "\n";
	return 0;
}
