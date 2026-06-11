#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll qsm(ll a,ll b)
{
	ll s=1;
	while(b)
	{
		if(b&1)s=s*a%mod;
		a=a*a%mod;
		b>>=(ll)1;
	}
	return s;
}
int main()
{
	ios;
	ll n;
	cin>>n;
	if(n<=1){cout<<0<<'\n';return 0;}
	ll a=(((qsm(10,n)%mod-qsm(9,n)%mod+mod)%mod-qsm(9,n)+mod)%mod+qsm(8,n))%mod;
	cout<<a<<'\n';
}