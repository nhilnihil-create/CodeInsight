#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.141592653589793238
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll MOD=1e9+7;


void solve()
{
	ll n,m;
	cin>>n>>m;
	vector<ll> a(n+1,0);
	for(ll i=0;i<m;i++)
	{
		ll c;
		cin>>c;
		a[c]=1;
	}
	// cout<<a[75]<<endl;;
	vector<ll> dp(n+2,0);
	dp[0]=1;
	if(a[1]==0)
		dp[1]=1;
	for(ll i=2;i<=n;i++)
	{
		if(a[i]==0)
		{
			/*if(i==45)
				cout<<"xx";*/
			dp[i]=dp[i-1]+dp[i-2];
			dp[i]%=MOD;
		}
		else
			dp[i]=0;
	}
	/*for(ll i=0;i<=n;i++)
		cout<<i<<"*"<<dp[i]<<endl;*/
	cout<<dp[n];
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
