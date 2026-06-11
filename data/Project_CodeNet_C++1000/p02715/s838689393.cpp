#include "bits/stdc++.h"
using namespace std;

const int N=1e5+20,MOD=1e9+7;

int n,k,dp[N],ans;

int mul(int a,int b) {return (1ll*a*b)%MOD;}

int power(int a,int b)
{
	int num=a,ans=1;
	while(b)
	{
		if(b&1) ans=mul(ans,num);
		b>>=1;
		num=mul(num,num);
	}
	return ans;
}

int main()
{
	cin>>n>>k;

	for(int i=k;i>=1;i--)
	{
		for(int j=2*i;j<=k;j+=i)
		{
			dp[i]=(dp[i]-dp[j])%MOD;
			if(dp[i]<0) dp[i]+=MOD;
		}
		dp[i]=(dp[i]+power(k/i,n))%MOD;
		ans=(ans+mul(i,dp[i]))%MOD;
	}

	printf("%d",ans);
}