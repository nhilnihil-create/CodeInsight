#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll a[maxn],b[maxn];
ll gcd(ll x,ll y)
{
	return y?gcd(y,x%y):x;
}
int main()
{
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]/2;
	}
	//ll ans=a[1],bans=b[1];
	ll lcm,blcm;
	lcm=a[1];
	blcm=b[1];   
	for(int i=2;i<=n;i++)
	{
		lcm=lcm*a[i]/gcd(lcm,a[i]);
		//ans=lcm;
		blcm=blcm*b[i]/gcd(blcm,b[i]);
		if(blcm>m)
		{
			cout<<0<<"\n";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ll cnt=blcm/b[i];
		if(cnt%2==0)
		{
			cout<<0<<"\n";
			return 0;
		}
	}
	//ll ans=m/blcm;
	//if(ans&1) ans=ans/2+1;
	//else ans=ans/2;
	//if(blcm>m) cout<<0<<"\n";
	//else 
	cout<<(m-blcm)/lcm+1<<"\n";
	//cout<<ans<<"\n";
	return 0; 
}