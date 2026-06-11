#include "bits/stdc++.h"
using namespace std;

const int N=2e3+20,MOD=1e9+7;

int n,m,a[N],b[N],dp[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) scanf("%d",&b[i]);

	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int j=0;j<=m;j++) dp[0][j]=1;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			if(a[i]!=b[j]) dp[i][j]-=dp[i-1][j-1];
			dp[i][j]%=MOD;
			if(dp[i][j]<0) dp[i][j]+=MOD;
		}
	}

	cout<<dp[n][m];
}