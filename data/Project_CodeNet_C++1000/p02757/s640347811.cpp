#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,MOD,ans;
int a[N],sum[N];
signed main(){
	scanf("%lld%lld",&n,&MOD);
	for (register int i=1; i<=n; ++i) scanf("%1lld",&a[i]);
	if (MOD==2 || MOD==5)
	{
		for (register int i=1; i<=n; ++i) if (a[i]%MOD==0) ans+=i;
		printf("%lld\n",ans);
	}
	else
	{
		sum[0]=1;
		int now=0,base=1;
		for (register int i=n; i>=1; --i)
		{
			now=(now+a[i]*base)%MOD;
			ans+=sum[now];
			sum[now]++; 
			base=base*10%MOD;	
		}
		printf("%lld\n",ans);
	}
return 0;	
}