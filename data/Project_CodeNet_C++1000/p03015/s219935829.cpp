#include <bits/stdc++.h>
using namespace std;
const int MOD = 1E9 + 7, N = 100005;
string s;
int n, a[N], dp[N][2];
int solve(int idx, int f)
{
	if (idx == n)
		return 1;
	else if (dp[idx][f] != -1)
		return dp[idx][f];
	int ans = 0, lim = 1;
	if (f)
		lim = a[idx];
	for (int i = 0; i <= lim; ++i)
	{
		int nf = f;
		if (f)
		{
			if (i < lim)
				nf = 0;
		}
		if (i)
			ans = (1LL * ans + (2 * solve(idx + 1, nf)) % MOD) % MOD;
		else
			ans = (1LL * ans + solve(idx + 1, nf)) % MOD;
	}
	return dp[idx][f] = ans;
}
int main(int argc, char const *argv[])
{
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; ++i)
	{
		a[i] = s[i] - '0';
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 1);
	return 0;
}