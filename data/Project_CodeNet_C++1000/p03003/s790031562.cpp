#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e3 + 20;
const int mod = 1e9 + 7;

int dp[maxn][maxn] , a[maxn] , b[maxn];

inline void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	for(int i = 1; i <= m; i++)
		cin >> b[i];

	dp[0][0] = 1;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= m; j++)
		{
			if(a[i] == b[j] && i && j)
				mkay(dp[i][j] += dp[i - 1][j - 1]);

			if(i)
				mkay(dp[i][j] += dp[i - 1][j]);
			if(j)
				mkay(dp[i][j] += dp[i][j - 1]);

			if(i && j)
				mkay(dp[i][j] -= dp[i - 1][j - 1]);
		}

	cout << dp[n][m] << endl;
}










 
