#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[505][505];
int n,k,h[305],b[305],he[305][305];
int main()
{
	scanf("%d%d",&n,&k);
	memset(dp,0x7f,sizeof(dp));
	ll ans=dp[0][0];
	int i,j;
	for(i=1;i<=n;i++) {
		scanf("%d",&h[i]);
		for(j=0;j<=k;j++) he[i][j]=h[i];
		//b[i]=h[i];
	}
	//sort(b+1,b+n+1);
	for(i=0;i<=k;i++)
	dp[0][i]=0;
//	for(i=1;i<=k;i++) dp[i][i]=0;
/*	for(i=1;i<=n;i++)
	  for(j=0;j<=k;j++){
	    if(h[i]>he[i-1][j])  dp[i][j]=min(dp[i][j],dp[i-1][j]+h[i]-he[i-1][j]);
	    else dp[i][j]=min(dp[i][j],dp[i-1][j]);
	    if(dp[i][j]>dp[i-1][j-1]&&j>=1){
	  	dp[i][j]=dp[i-1][j-1];
	  	he[i][j]=he[i-1][j-1];
		}
	  }
	for(i=1;i<=n;i++){
		 for(j=0;j<=k;j++) printf("%d ",dp[i][j]);
		 printf("\n");
	}
	 
	cout<<dp[n][k];*/
	for(i=1;i<=n+1;i++)
	  for(j=0;j<=min(k,i-1);j++)
	    for(int ii=0;ii<=j;ii++) 
		if(h[i]>h[i-ii-1])dp[i][j]=min(dp[i][j],dp[i-ii-1][j-ii]+h[i]-h[i-ii-1]);
		else dp[i][j]=min(dp[i][j],dp[i-ii-1][j-ii]);
	for(i=0;i<=k;i++) ans=min(ans,dp[n+1][i]);
	cout<<ans; 
	return 0;
}