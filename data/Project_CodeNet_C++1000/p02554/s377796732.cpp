#include<cstdio>
typedef long long ll;
const ll mod=1e9+7;
ll dp[1000001][2][2];
int main()
{
	int n;
	scanf("%d",&n);
	dp[0][0][0]=1;
	for(int i=0;i<n;++i)
		for(int j=0;j<=1;++j)
			for(int k=0;k<=1;++k)
				dp[i+1][j][k]+=dp[i][j][k]*8,dp[i+1][j][k]%=mod,dp[i+1][j|1][k]+=dp[i][j][k],dp[i+1][j|1][k]%=mod,dp[i+1][j][k|1]+=dp[i][j][k],dp[i+1][j][k|1]%=mod;;
	printf("%lld",dp[n][1][1]);
} 