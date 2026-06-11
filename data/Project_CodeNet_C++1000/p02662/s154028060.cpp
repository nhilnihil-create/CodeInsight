#include<bits/stdc++.h>
using namespace std;

const int N=3005,inv=499122177;
const int MOD=998244353;
int n,s,a[N];
long long p[N],dp[N][N],ans;

int main()
{
	scanf("%d%d",&n,&s),p[0]=1;
	for(int i=1;i<=n;i++) p[i]=p[i-1]*2%MOD;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		dp[i-1][0]=p[n];
		for(int j=1;j<=s;j++)
		{
			dp[i][j]=dp[i-1][j];
			if(j>=a[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]]*inv%MOD)%MOD;
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
		}
	}
	printf("%lld\n",dp[n][s]);
}