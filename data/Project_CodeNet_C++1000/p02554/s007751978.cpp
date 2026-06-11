#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
/*ll qcheng(ll x,ll y)
{
	ll res=0;
	while(y)
	{
		if(y&1) res=(res+x)%mod;
		y/=2;
		x=x*2%mod;
	}
	return res%mod;
}*/
ll fpower(ll base,ll mi)
{
	ll res=1;
	while(mi)
	{
		//if(mi&1) res=qcheng(res,base)%mod;
		if(mi&1) res=res*base%mod;
		mi/=2;
		//base=qcheng(base,base)%mod;
		base=base*base%mod;
	}
	return res%mod;
}
int main()
{
	ll n;
	cin>>n;
	ll cnt=fpower(10,n);
	ll ans=fpower(9,n);
	ll arr=fpower(8,n);
	cout<<((cnt-2*ans+arr)%mod+mod)%mod<<"\n";
	return 0;
}