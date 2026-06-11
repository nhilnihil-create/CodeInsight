	#include <bits/stdc++.h>
	#include <set>
	#define ll long long 
	#include <string>
	#define pb push_back
	#define mp make_pair
	# define pi 3.14159265358979323846
	#define mod 1000000007
	#define rep(i,n) for(i=0;i<n;i++)
	#define repk(i,k,n) for(i=k;i<n;i++)
	using namespace std;
	void fastio()
	{
		#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	    #endif
	    ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	    cout.tie(NULL);

	}
	ll int multiply(ll int a,ll int b)
	{
		ll int ans=(a%mod*b%mod)%mod;
		return ans;
	}
	ll int add(ll int a, ll int b)
	{
		ll int ans=(a%mod+b%mod)% mod;
		return ans;
	}
	ll int vis[100001]={0};
vector< vector<ll int> >adj(100001);
	void dfs(ll int n)
	{
		vis[n]=1;
		for(auto child: adj[n])
		{
			if (vis[child]==0)
				dfs(child);
		}
	}


	void solve()
	{
		ll int n,m;
		cin>>n>>m;
		while(m--)
		{
			ll int x,y;
			cin>>x>>y;	
			adj[x].pb(y);
			adj[y].pb(x);
		}
		ll int i;
		ll int ans=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0 && adj[i].size()>0)
				{dfs(i);
					ans++;}
		}
		ans--;
		
		repk(i,1,n+1)
		{if(vis[i]==0)
			ans++;}
			cout<<ans<<endl;

		

	}
		
	int main()
	{ 
		fastio();
	    ll int t;
	    // cin>>t;
	    t=1;
	    while(t--)
	    {
	    	solve();
	    }
	}

		
			
		
		
		
		



