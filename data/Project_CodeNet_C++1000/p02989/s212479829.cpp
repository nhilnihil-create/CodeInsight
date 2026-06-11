#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll n,ans=0;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	ll x=ceil(n/2.0);
		cout<<a[x]-a[x-1];
	// cout<<ans;
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