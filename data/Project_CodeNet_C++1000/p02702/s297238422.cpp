#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,mod=2019,m[N];
long long dp[N],p[N],ans;
char a[N];

int main()
{
	scanf(" %s",a+1);
	n=strlen(a+1);

	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		p[i]=(p[i-1]*10)%mod;
		dp[i]=(dp[i-1]*10+a[i]-'0')%mod;
	}

	m[0]++;
	for(int i=1;i<=n;i++)
	{
		dp[i]=(dp[i-1]+(a[i]-'0')*p[n-i])%mod;
		m[dp[i]]++;
		ans+=m[dp[i]]-1;
	}

	printf("%lld",ans);
}