#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int M=305;
const LL INF=(LL)M*(1000000000);

LL dp[M][M]; // dp[i][j] i block end at j
// if k=0 ans=\sum_{1~n} {h[i]-h[i-1]} (h[0]=0)
// if k>0 should change k blocks as the left one of themselves

LL h[M];

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&h[i]);
	for(int i=1;i<=n-k;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==1)
			{
				dp[i][j]=h[j];
				continue;
			}
			dp[i][j]=INF;
			for(int k=i-1;k<j;k++)
				dp[i][j]=min(dp[i][j],dp[i-1][k]+max(0LL,h[j]-h[k]));
			//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	LL ans=INF;
	for(int i=n-k;i<=n;i++)
		ans=min(ans,dp[n-k][i]);
	printf("%lld\n",ans);
	return 0;
}