#include <bits/stdc++.h>
using namespace std;
long long n,dp[2005]={0,0,0,1,1,1};
const long long mod=1000000007;
int main()
{
	scanf("%d",&n);
	for(int i=6;i<=n;i++)
	{
		for(int j=0;j<=i-3;j++)
		{
			dp[i]=(dp[i]+dp[j])%mod;
		}
		dp[i]+=1;
		dp[i]%=mod;
	}
	printf("%lld\n",dp[n]);
 	return 0;
}
