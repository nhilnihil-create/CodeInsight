#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod=1000 * 1000 * 1000 + 7;
ll mul(ll a, ll b)
{
	return ((a%mod)*(b%mod))%mod;
}
ll add(ll a, ll b)
{
	return ((a%mod)+(b%mod))%mod;
}
ll sub(ll a, ll b)
{
	return ((a%mod)-(b%mod)+mod)%mod;
}
ll n,m,v,p;
ll a[100005];
bool ch(ll x)
{
	if(x<p)
	{
		return 1;
	}
	if(a[x]+m<a[p-1])
	{
		return 0;
	}
	
	ll u=v-(p-1)-(n-x);
	u*=m;
	//cout<<x<<" "<<u<<"\n";
	for(ll i=p-1;i<x;i++)
	{
		u-=abs(a[x]+m-a[i]);
	}
	if(u<=0)
	{
		return 1;
	}
	else 
		return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>v>>p;
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	ll l=0,h=n-1;
	while(h-l>1)
	{
		ll m=(h+l)/2;
		if(ch(m))
		{
			l=m;
		}
		else
		{
			h=m;
		}
	}
	if(ch(h))
	{
		cout<<h+1;
	}
	else
	{
		cout<<l+1;
	}
}
