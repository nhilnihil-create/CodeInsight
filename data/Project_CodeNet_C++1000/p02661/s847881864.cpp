 /*
    Created by Ezio112
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
ll inf(1e18);
#define mod ll(1e9+7)
//#define mod ll(998244353)
#define ff first
#define ss second
ll power(ll a,ll b)
{
	if(!b)
		return 1;
	ll dp=power(a,b/2)%mod;
	
	if(b&1) return (((dp*dp)%mod)*a)%mod;
	
	return (dp*dp)%mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test=1;
    //cin>>test;

    while(test--)
    {
		ll n;
		cin>>n;
		vector<ll> a(n),b(n);
		
		for(ll i=0;i<n;++i)
		cin>>a[i]>>b[i];
		
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		
		ll left,right;
		if(n&1)
		{
			left=a[n/2];
			right=b[n/2];
			cout<<right-left+1;
		}
		else {
			left=a[n/2]+a[n/2-1];
			right=b[n/2]+b[n/2-1];
			cout<<(right-left)+1;
		}
			
	}
	return 0;
}
