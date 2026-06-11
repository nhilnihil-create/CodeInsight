#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;
const int N = 2e5;
ll fact[N+100],inv[N+100];

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
	fact[0] = inv[0] = 1;
	for(int i=1;i<=N;i++){
		fact[i] = (fact[i-1]*i)%mod;
		inv[i] = bigmod(fact[i],mod-2);
	}
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	ll ans = bigmod(2,n);
	ans = (ans-1+mod)%mod;
	ll mina = 1,minb = 1;
	for(int i=n;i>n-a;i--){
		mina = (mina*i)%mod;
	}
	for(int i=n;i>n-b;i--){
		minb = (minb*i)%mod;
	}
	mina = (mina*inv[a])%mod;
	minb = (minb*inv[b])%mod;
	ans = (ans-mina+mod)%mod;
	ans = (ans-minb+mod)%mod;
	printf("%lld\n",ans);
}
