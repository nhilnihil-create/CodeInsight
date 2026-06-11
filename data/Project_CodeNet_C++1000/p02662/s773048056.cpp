#include <bits/stdc++.h>
using namespace std;
using ll = int_fast64_t;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = (1 << 30) - 1;
const ll infll = (1LL << 61) - 1;
#define fast() ios::sync_with_stdio(false), cin.tie(nullptr)
#define digit(N) cout << fixed << setprecision((N))
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

int N, S;

int main()
{
	cin >> N >> S;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	vector<vector<ll>> dp(N + 1, vector<ll>(S + 1));

	dp[0][0] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= S; j++)
		{
			if (j + a[i] <= S)
			{
				dp[i + 1][j + a[i]] += dp[i][j] % mod2;
			}
			dp[i + 1][j] += 2 * dp[i][j] % mod2;
			dp[i + 1][j] %= mod2;
		}
	}
	cout << dp[N][S] << "\n";
}