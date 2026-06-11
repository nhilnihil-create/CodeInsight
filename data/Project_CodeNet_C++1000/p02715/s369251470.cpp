#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int N = 1e5;
ll cnt[N+100];

ll bigmod(ll a,ll b)
{
	if(b==0){
		return 1;
	}
	ll x = bigmod(a,b/2);
	x = (x*x)%mod;
	if(b%2){
		x = (x*a)%mod;
	}
	return x;
}
int main()
{
	int n,k;
	ll ans = 0;
	scanf("%d%d",&n,&k);
	for(int i=k;i>0;i--){
		ll minus = 0;
		int p = 1;
		for(int j=i+i;j<=k;j+=i){
			minus = (minus+cnt[j])%mod;
			p++;
		}
		ll total = bigmod(p,n);
		cnt[i] = (total-minus+mod)%mod;
		//printf("%lld\n",cnt[i]);
		ans = (ans+(cnt[i]*i)%mod)%mod;
	}
	printf("%lld\n",ans);
}
