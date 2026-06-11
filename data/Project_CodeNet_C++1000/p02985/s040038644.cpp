#include <bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7ll ;
const int MAX = 1e5 + 10 ;

int arr[MAX] ;
long long n , k ;

vector< vector<int> >adj(MAX) ;

long long ans = 1ll ;

void dfs(int node , int par , int lvl)
{
	long long cnt = 0 ;
	for(auto &child : adj[node])
	{
		if(child == par)
			continue ;
		long long x = max(0ll , k-min(2 , lvl+1)*1ll-cnt) ;
		ans = (ans * x) % mod ;
		dfs(child , node , lvl+1) ;
		cnt++ ;
	}
	return ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>k ;
	for(int i = 0 ; i < n-1 ; ++i)
	{
		int x , y ;
		cin>>x>>y ;
		adj[x].push_back(y) ;
		adj[y].push_back(x) ;
	}
	ans = k ;
	dfs(1 , -1 , 0) ;
	return cout<<ans<<"\n" , 0 ;
}		