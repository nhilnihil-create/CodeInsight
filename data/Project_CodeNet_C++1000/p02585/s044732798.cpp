//wa&ac
#include<stdio.h>
#define N 5005
typedef long long ll;
int to[N][40];
ll sum[N][40],dp[N][40]; //dp[i][j]:i节点走2^j步得到的最大分 
#define mx(a,b) ((a)>(b)?(a):(b))
int main()
{
	int n,i,j,now,nex;
	ll k,ans=-1000000009,cnt,tot,packup;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;++i)
		scanf("%d",to[i]);
	for(i=1;i<=n;++i)
		scanf("%lld",sum[i]);
	for(i=1;i<=n;++i)
		dp[i][0]=sum[i][0];
	for(i=0;i<33;++i)
	{
		for(j=1;j<=n;++j)
		{
			nex=to[j][i];
			to[j][i+1]=to[nex][i];
			sum[j][i+1]=sum[j][i]+sum[nex][i];
			dp[j][i+1]=mx(dp[j][i],sum[j][i]+dp[nex][i]);
		}
	}
	packup=k;
	for(i=1;i<=n;++i)
	{
		cnt=-1000000009;
		now=i;
		tot=0;
		for(j=0;k>0;++j)
		{
			if(k&1)
				ans=mx(ans,mx(dp[i][j],tot+dp[now][j])),tot+=sum[now][j],now=to[now][j];
			k/=2;
		}
		k=packup;
	}
	printf("%lld",ans);
	return 0;
}