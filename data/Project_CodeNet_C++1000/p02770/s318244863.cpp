#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[5003];
ll c[5003];
int main(void)
{
	ll k,q;
	scanf("%lld%lld",&k,&q);
	for(ll i=0;i<k;i++)
	{
		scanf("%lld",&d[i]);
	}
	while(q--)
	{
		ll n,x,m;
		scanf("%lld%lld%lld",&n,&x,&m);
		ll ans=n-1;
		ll sum=0;
		ll zero=0;
		for(ll i=0;i<k;i++) 
		{
			c[i]=d[i]%m;
			if(c[i]==0) zero++;
			sum+=c[i];
		}
		ans-=((n-1)/k)*zero;
		ll dn=((n-1)/k)*sum;
		for(ll i=0;i<(n-1)%k;i++)
		{
			dn+=c[i];
			if(c[i]==0) ans--;
		}
		ans-=(dn+x)/m-x/m;
		printf("%lld\n",ans);
	}
}