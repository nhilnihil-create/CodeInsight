#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
const int N = 1e6;
ll fac[N],inv[N];
ll binpow(ll a,ll pow)
{
	ll res = 1ll;
	while(pow)
	{
		if(pow&1)		res = (res*a)%mod;
		a = (a*a)%mod;
		pow/=2;		
	}
	return res;
}
void build()
{
	fac[0] = fac[1] = 1ll;
	for(int i=2;i<N;++i)		fac[i] = (fac[i-1]*i)%mod;
	inv[N-1] = binpow(fac[N-1],mod-2);
	for(int i=N-2;i>=0;i--)		inv[i] = (inv[i+1]*(i+1))%mod;
}
ll nCk(int n,int k)
{
	return fac[n]*inv[k]%mod*inv[n-k]%mod;
}
int main()
{
	build();
	int i,j,n,k;
	cin>>n>>k;
	ll ans = 0ll;
	ll dp[k+1];
	for(i=0;i<=k;++i)		dp[i] = 0ll;
	for(i=k;i>=1;i--)
	{
		int d = k/i;
		dp[i] = binpow(d,n);
		for(j=i*2;j<=k;j+=i)
		{
			dp[i] = (dp[i] - dp[j] + mod)%mod;
		}
		ans = (ans + i*dp[i])%mod;
	}
/*	for(i=1;i<=k;++i)
	{
		int d = k/i;
		ans = (ans + binpow(d,n))%mod;
	}		*/
	cout<<ans;
}