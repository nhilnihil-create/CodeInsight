#include<bits/stdc++.h>
using namespace std;
#define sz 10010
#define MOD 998244353
#define ll long long

inline ll add(ll a, ll b)
{
	a = ((a % MOD) + MOD) % MOD;
	b = ((b % MOD) + MOD) % MOD;
	return (a + b) % MOD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, s; cin >> n >> s;
	vector<int>a(n);
	for (auto &it : a)
		cin >> it;
	vector<vector<ll>>dp(n + 1, vector<ll>(s + 1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= s; j++)
		{
			dp[i + 1][j] = add(dp[i + 1][j], add(dp[i][j], dp[i][j]));
			if (j + a[i] <= s)
				dp[i + 1][j + a[i]] = add(dp[i + 1][j + a[i]], dp[i][j]);
		}
	}
	cout << dp[n][s];

	return 0;
}