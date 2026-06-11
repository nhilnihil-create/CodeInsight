#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll n;
	cin>>n;
	ll a[n];
	ll sum=0;
	for(ll i=0;i<n;i++)
		cin>>a[i],sum+=a[i];
	ll cnt=0;
	for(ll i=0;i<n;i++)
	{
		if(i%2==1)
			cnt+=a[i];
	}
	ll ans[n]{};
	ans[0]=sum-2*cnt;
	for(ll i=1;i<n;i++)
	{
		ans[i]=2*a[i-1]-ans[i-1];
	}
	for(ll i=0;i<n;i++)
		cout<<ans[i]<<" ";
    return;
}

int main()
{
        fast;
        ll q;
        q=1;
        // cin>>q;
        while(q--)
        	solve();
        
        return 0;
}
