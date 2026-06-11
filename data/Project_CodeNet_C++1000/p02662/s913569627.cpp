#include <stdio.h>
#define LL long long
#define maxn 3010
#define mod 998244353
LL dp[maxn];
int main(){
	int n,s,x,i,j,inv2;
	scanf("%d%d",&n,&s);
	inv2=mod-mod/2,dp[0]=1;
	for(i=1;i<=n;i++)dp[0]=dp[0]*2%mod;
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		for(j=s;j>=x;j--)
			dp[j]=(dp[j]+dp[j-x]*inv2)%mod;
	}
	printf("%lld\n",dp[s]);
	return 0;
}