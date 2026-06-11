#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
ll KS(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1)
		{
			x=x*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return x;
}
int main()
{
	ll n;
	cin>>n;
	ll sum;
	sum=(KS(10,n)-2*(KS(9,n))+KS(8,n))%mod;
	sum=(sum+mod)%mod;
	cout<<sum<<endl;
}