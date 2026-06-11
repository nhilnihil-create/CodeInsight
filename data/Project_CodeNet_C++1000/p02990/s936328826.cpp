#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int mn=2006,mod=1e9+7;
int fac[mn],inv[mn];

int poww(int a,int b)
{
	LL ans=1,tp=a;
	while(b) {
		if(b&1) ans=ans*tp%mod;
		tp=tp*tp%mod;
		b>>=1;
	}
	return ans;
}

int calc(int n,int m)
{
	if(m>n) return 0;
	return (1ll*fac[n]*inv[m]%mod)*inv[n-m]%mod;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;++i) fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=poww(fac[n],mod-2);
	for(int i=n-1;i>=1;--i) inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=1;i<=k;++i) {
		LL ans=1ll*calc(k-1,i-1)*calc(n-k+1,i)%mod;
		printf("%lld\n",ans);
	}
}