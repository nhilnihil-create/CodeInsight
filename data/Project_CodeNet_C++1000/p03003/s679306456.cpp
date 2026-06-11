#include<bits/stdc++.h>
typedef long long ll;
typedef double ld;

using namespace std;

ll mod = 1e9+7;

int main()
{
	ll n,m; cin>>n>>m;
	int A[n], B[m];

	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	for(int j=0;j<m;j++)
		cin>>B[j];

	long long  dp[n+1][m+1];
	memset(dp, 0, sizeof(0));

	for(int i=0;i<=n;i++)
	{
		dp[i][0] = 1;
	}
	for(int j=0;j<=m;j++)
		dp[0][j] = 1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = dp[i-1][j]+ dp[i][j-1] - dp[i-1][j-1];
			if(A[i-1] == B[j-1])
			{
				dp[i][j]+=dp[i-1][j-1];
			}

			dp[i][j]+=mod;
			dp[i][j]%=mod;
		}
	}
	

	
	cout<<dp[n][m]<<endl;
}