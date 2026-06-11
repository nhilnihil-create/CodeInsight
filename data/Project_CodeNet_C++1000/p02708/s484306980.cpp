#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main()
{
	ll n,k;
	cin>>n>>k;
	vector<ll>pf(n+2);
	ll sum=0;
	for(int i=0; i<=n; i++)
	{
		sum+=i;
		pf[i+1]=sum;
	}
	ll ans=0;
	for(int i=k; i<=n+1; i++)
	{
		ll low=pf[i];
		ll high=pf[n+1]-pf[n+1-i];
	    ans=(ans+(high-low+1))%mod;
	}
	cout<<ans;
	return 0;
	
}