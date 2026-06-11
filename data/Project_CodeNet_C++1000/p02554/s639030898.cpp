#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long int ll;
const ll mod=1e9+7;
ll ksm(ll a,ll b){
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	ll a;
	scanf("%lld",&a);
	ll ans=0;
	ans=(ksm(10,a)+ksm(8,a)%mod-2*ksm(9,a))%mod+mod;
	printf("%lld\n",ans%mod);
}