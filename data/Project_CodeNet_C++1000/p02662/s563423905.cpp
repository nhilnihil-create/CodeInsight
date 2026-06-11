#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007ll
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define db(x) cout << #x << " = " << x << '\n'
#define sep cout << "********************************************\n"
#define fast ios_base::sync_with_stdio(false), cin.tie(NULL)
ll dp[3003][3003], n, s, a[3003], MOD = 998244353;
int main(int argc, char const *argv[])
{
	fast;
	cin >> n >> s;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= s; ++j)
		{
			dp[i][j] = (2 * dp[i - 1][j]) % MOD;
		}
		for (int j = 0; j <= s - a[i]; ++j)
		{
			dp[i][j + a[i]] = (dp[i][j + a[i]] + dp[i - 1][j]) % MOD;
		}
		// for (int j = 1; j <= s; ++j)
		// {
		// 	cout << dp[i][j] << ' ';
		// }
		// cout << '\n';
	}
	cout << dp[n][s];
	return 0;
}