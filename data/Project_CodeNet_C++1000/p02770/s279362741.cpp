#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,T;
int d[1000001];
signed main()
{
	scanf("%lld%lld",&n,&T);
	for(int i=0;i<n;i++)
		scanf("%lld",&d[i]);
	while(T--)
	{
		int m,x,mod;
		scanf("%lld%lld%lld",&m,&x,&mod);
		m--;
		int u=0,tot=0;
		for(int i=0;i<n;i++)
		{
			u+=d[i]%mod;
			if(d[i]%mod==0)
				tot++;
		}
		tot*=m/n;
		u=u*(m/n)+x%mod;
		for(int i=0;i<m%n;i++)
		{
			u+=d[i]%mod;
			if(d[i]%mod==0)
				tot++;
		}
		printf("%lld\n",m-tot-u/mod);
	}
	return 0;
}
