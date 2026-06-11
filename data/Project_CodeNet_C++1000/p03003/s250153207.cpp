#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_NM = 2005;
const ll MOD = 1e9+7;
ll S[MAX_NM],T[MAX_NM];
ll dp[MAX_NM][MAX_NM],sum[MAX_NM][MAX_NM];

int main()
{
	ll N,M;
	cin >> N >> M;
	rep(i,N)
	{
		cin >> S[i];
	}
	rep(i,M)
	{
		cin >> T[i];
	}

	dp[0][0] = 1;
	sum[1][1] = 1;
	rep(i,N+1)
	{
		rep(j,M+1)
		{
			if (i-1 >= 0 && j-1 >= 0 && S[i-1] == T[j-1])
			{
				dp[i][j] = sum[i][j];
			}
			sum[i+1][j+1] = ((((sum[i+1][j] + sum[i][j+1]) % MOD) + MOD - sum[i][j]) % MOD + dp[i][j]) % MOD;
		}
	}
	cout << sum[N+1][M+1] << endl;
	return 0;
}