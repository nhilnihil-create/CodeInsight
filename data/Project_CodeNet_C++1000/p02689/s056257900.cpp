//Solution By SlavicG
#include "bits/stdc++.h"
using namespace std;
 
#define ll                          long long
 
#define forn(i,n)                   for(int i=0;i<n;i++)
#define all(v)                      v.begin(), v.end()
#define rall(v)                     v.rbegin(),v.rend()
	
#define pb                          push_back
#define sz(a)                       (int)a.size()
 
#define   endl                       "\n"
#define fastio                       ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int  main()
{
	int n,m;
	cin >> n >> m;
	int a[n];
	vector<int> adj[n];
	forn(i,n)
	{
		cin >> a[i];
	}
	forn(i,m)
	{
		int x,y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int ans = n;
	for(int i=  0;i < n;i++)
	{
		bool del = false;
		for(auto x : adj[i])
		{
			if(a[i] <= a[x])
			{
				del = true;
			}
		}
		if(del)ans--;
	}
	cout << ans << endl;
}