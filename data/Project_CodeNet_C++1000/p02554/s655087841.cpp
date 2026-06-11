#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)
		{
			ans=ans*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return ans;
}
int main()
{
	ll n;
	cin>>n;
	ll ans=(ksm(10,n)-ksm(9,n)-ksm(9,n)+ksm(8,n))%mod;
	ans=(ans+mod)%mod; 
	cout<<ans<<endl;
	return 0;
}
