
/**
*   author:  akifpathan
*   created: Sunday 27.09.2020 06:04:08 PM
**/

/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#ifdef LOCAL
#include "debug.h"
#else
#include<bits/stdc++.h>
using namespace std;
#define debug(x...)
#endif
 
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using ordered_set= tree<T, null_type, 
		less<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
template<class T> 		
using ordered_mset= tree<T, null_type, 
		less_equal<T>, 
		rb_tree_tag, tree_order_statistics_node_update> ;
		
*/
 
/*
 
PBDS
-------------------------------------------------
			0 based indexing
-------------------------------------------------			 
1) insert(value)
2) erase(value)
3) order_of_key(value) // Number of items strictly smaller than value
4) *find_by_order(k) : K-th element in a set (counting from zero)
 
*/
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());	

const int mx=1e5+5;

int color[mx];
vector<int>g[mx];

void dfs(int u)
{
	color[u]=1;
	for(int v: g[u]) if(!color[v]) dfs(v);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;i++) 
	{
		int u,v;
		cin>>u>>v;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	int ans=-1;
	
	for(int i=1;i<=n;i++)
	{
		if(!color[i])
		{
			ans++;
			dfs(i);
		}
	}
	
	cout<<ans;
}		

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int testcase=1;
	//cin>>testcase;
	
	for(int i=1;i<=testcase;i++)
	{
		//cout<<"Case "<<i<<": ";
		solve();
	}
	
	#ifdef LOCAL
	cerr<<"\nTime elapsed: " << 1000.0 * clock() / CLOCKS_PER_SEC << " ms\n";
	#endif
	
	
	return 0;
}

