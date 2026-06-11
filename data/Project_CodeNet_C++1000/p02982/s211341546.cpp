#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll n,d;
	cin>>n>>d;
	ll a[n][d];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<d;j++)
			cin>>a[i][j];
	ll ans=0;
	for(ll i=0;i<n;i++)
	{
		
		for(ll j=i+1;j<n;j++)
		{
			ll x=0;
			for(ll k=0;k<d;k++)
			{
				x+=((a[i][k]-a[j][k])*(a[i][k]-a[j][k]));
			}
			if(floor(sqrt(x))==ceil(sqrt(x)))
				ans++;
		}
			
	}
	cout<<ans;
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