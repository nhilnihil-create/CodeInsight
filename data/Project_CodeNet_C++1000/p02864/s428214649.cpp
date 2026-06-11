#include <bits/stdc++.h>
using std::min;
int n,m,a[305];
long long dp[305][305][305],ans;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<=i;j++)
			for (int k=0;k<=m;k++){
				if (dp[i][j][k]>10000000000000) continue;
				dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]);
				dp[i+1][i+1][k]=min(dp[i+1][i+1][k],dp[i][j][k]+std::max(0,a[i+1]-a[j]));
			}
	ans=1000000000000;
	for (int i=0;i<=m;i++)
		for (int j=0;j<=n;j++) ans=min(ans,dp[n][j][i]);
	printf("%lld\n",ans);
} 