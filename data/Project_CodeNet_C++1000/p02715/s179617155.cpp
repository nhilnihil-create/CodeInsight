#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll exp(ll a,ll b)
{
	if(b==0)
	 return 1;
	if(b%2==0)
	 return exp(a*a%mod,b/2);
	return a*exp(a*a%mod,(b-1)/2)%mod;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll>dp(k+1);
	ll ans=0;
	for(ll i=k; i>=1; i--)
	{
		ll temp=exp(k/i,n);
		for(ll x=2; i*x<=k; x++)
		{
			temp=(temp-dp[i*x]+mod)%mod;
		}
	    dp[i]=temp;
	    ans=(ans+i*dp[i])%mod;
	}
	cout<<ans;
	return 0;
}