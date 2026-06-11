#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define COUT cout<<fixed<<setprecision(12)
#define CIN getline(cin,s)
ll MOD=1000000007;

void solve()
{
	ll n,k;
	cin>>n>>k;
	ll p[n+1];
	for(ll i=0;i<n;i++)
	{
		cin>>p[i];
		p[i]--;
	}
	
	ll c[n+1];
	for(ll i=0;i<n;i++)
	cin>>c[i];
	
	ll ans=INT_MIN;
	for(ll i=0;i<n;i++)
	{
		
		ll b[n+2]={0};
		ll j=p[i];
		vector<ll>v;
		v.push_back(0);
		while(b[j]==0)
		{
			v.push_back(c[j]);
			b[j]=1;
			j=p[j];
			
		}
		ll m=v.size()-1;
		
		for(ll j=1;j<=m;j++)
		v[j]=v[j]+v[j-1];
		
		ll val=INT_MIN;
		
		if(k>(m) && v[m]>0)
		{
			ll a=k/(m);
			ll d=k%(m);
			ll x=a*(v[m]);
			ll y=(a-1)*(v[m]);
			ll p=0;
			for(ll j=1;j<=d;j++)
			p=max(v[j],p);
			ll q=0;
			for(ll j=1;j<=m;j++)
			q=max(v[j],q);
			
			x=x+p;
			y=y+q;
			val=max(x,y);
		}
		else if(v[m]<0 && k>m)
		{
			for(ll j=1;j<=m;j++)
			val=max(val,v[j]);
		}
		else if(k<=m)
		{
			for(ll j=1;j<=k;j++)
			val=max(val,v[j]);
		}
		
		ans=max(ans,val);
	}
	cout<<ans;
}
int main()
{
	ll t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
}