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
	vector<string> s(n);
	for(ll i=0;i<n;i++)
		cin>>s[i];
	
	vector<vector<ll>> l(n,vector<ll> (m,0));
	vector<vector<ll>> r(n,vector<ll> (m,0));
	vector<vector<ll>> u(n,vector<ll> (m,0));
	vector<vector<ll>> d(n,vector<ll> (m,0));
	// cout<<1;
	ll c=0;
	for(ll i=0;i<n;i++)
	{
		c=0;
		for(ll j=0;j<m;j++)
		{
			if(s[i][j]=='.')
			{
				c++;
				l[i][j]=c-1;
			}
			else
				c=0;
		}
	}
	for(ll i=0;i<n;i++)
	{
		c=0;
		for(ll j=m-1;j>=0;j--)
		{
			if(s[i][j]=='.')
			{
				c++;
				r[i][j]=c-1;
			}
			else
				c=0;
		}
	}
	for(ll i=0;i<m;i++)
	{
		c=0;
		for(ll j=0;j<n;j++)
		{
			if(s[j][i]=='.')
			{
				c++;
				u[j][i]=c-1;
			}
			else
				c=0;
		}
	}
	for(ll i=0;i<m;i++)
	{
		c=0;
		for(ll j=n-1;j>=0;j--)
		{
			if(s[j][i]=='.')
			{
				c++;
				d[j][i]=c-1;
			}
			else
				c=0;
		}
	}
	ll ans=0;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<m;j++)
			ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]+1);
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
