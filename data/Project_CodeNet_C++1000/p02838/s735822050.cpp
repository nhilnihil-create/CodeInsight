#include<cstdio>
#define mod 1000000007
	int n;
	long long f[300005],ans=0;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&f[i]);
	for (int k=0;k<=60;k++)
	{
		int x=0,y=0,cnt=0;
		for (int i=1;i<=n;i++) if (f[i]&(1ll<<k)) ++x;else ++y;
		for (int i=1;i<=n;i++) if (f[i]&(1ll<<k)) cnt=(cnt+y)%mod,--x;else cnt=(cnt+x)%mod,--y;
		ans=(ans+(1ll<<k)%mod*cnt%mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}