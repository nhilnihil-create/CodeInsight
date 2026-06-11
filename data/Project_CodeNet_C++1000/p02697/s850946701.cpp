#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int main(void)
{
	scanf("%d%d",&n,&m);
	if(n%2==1)
	{
		for(ll i=1;i<=m;i++)
		{
			printf("%lld %lld\n",i,n-i+1);
		}
	}
	else
	{
		ll cnt=0;
		for(ll i=1;i<=n/2/2;i++)
		{
			cnt++;
			printf("%lld %lld\n",i,n/2-i+1);
			if(cnt==m) return 0;
		}
		for(ll i=1;i<=n/2/2;i++)
		{
			cnt++;
			printf("%lld %lld\n",i+n/2,n-i);
			if(cnt==m) return 0;
		}
	}
}