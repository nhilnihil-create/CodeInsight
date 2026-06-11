#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007


void solve()
{
	ll n,sum=0;
	cin>>n;
	vector<ll> a(n);
	for(ll i=0;i<n;i++)
		cin>>a[i],sum+=a[i];;
	ll sum1=0,ans=1000000007;
	for(ll i=0;i<n-1;i++)
	{
		sum1+=a[i];
		sum-=a[i];
		ans=min(ans,abs(sum-sum1));
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
