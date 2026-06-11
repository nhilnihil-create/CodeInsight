#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll l,r;
	cin>>l>>r;
	if(r-l>=2019)
	{
		cout<<0;
		return;
	}
	ll ans=2018;
	for(ll i=l;i<=r;i++)
	{
		for(ll j=i+1;j<=r;j++)
			ans=min(ans,((i*j)%2019));
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
