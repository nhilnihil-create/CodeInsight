#pragma GCC optimize("Ofast")
#include<stdio.h>
#include<algorithm>
using namespace std;
long long num[3005],dp[3005][3005]={0},mod=998244353;
int main(){
	long long i,j,n,s;
	scanf("%lld%lld",&n,&s);
	for(i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=s;j++){
			dp[i][j]=dp[i-1][j]*2%mod;	
			if(j>=num[i])
				dp[i][j]=(dp[i][j]+dp[i-1][j-num[i]])%mod;
		}
	}
	printf("%lld\n",dp[n][s]);
}