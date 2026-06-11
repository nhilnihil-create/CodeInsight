
	#include <bits/stdc++.h>
	using namespace std;
	
	typedef long long ll;
	#define pi 3.14159265 
	#define EPS 1e-8
	
	#define mod 1000000007
	#define fi first
	#define se second
	#define mp make_pair
	#define pb push_back
	#define endl "\n"

	const ll INF=(ll)3e17;
	
	ll memo[2005][2005];
	vector<pair<ll,ll> > v;
	ll dp(ll idx,ll l,ll r)
	{
		if(l>r)
			return 0;
		if(memo[l][r]!=-1)
			return memo[l][r];
			
		ll ans=max(dp(idx+1,l+1,r)+ v[idx].fi*(abs(l-v[idx].se)),dp(idx+1,l,r-1)+v[idx].fi*(abs(r-v[idx].se)));
		return memo[l][r]=ans;
	}
	
	
	int main()
	{
		 ios_base::sync_with_stdio(false);
		 cin.tie(NULL);
		 
		ll n;
		cin>>n;
		
		v=vector<pair<ll,ll> >(n);
		for(ll i=0;i<n;i++)
		{
			cin>>v[i].fi;
			v[i].se=i;
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		memset(memo,-1,sizeof(memo));
		cout<<dp(0,0,n-1);
	}
