#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define F first
#define S second
#define f(i,s,n) for(int i=(int)s;i<=(int)n;++i)
#define Fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N=2e5+5;
vector< set<int> > adj(N);
vector<bool> vis(N,false);
set<int> S;
void dfs(int s){
	vis[s]=1;
	for(auto  it:adj[s]){
		if(!vis[it]){
			S.insert(it);
			dfs(it);
		}
	}

}
void solve()
{
	int n,m;cin>>n>>m;
	f(i,1,m){
		int u,v;cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	f(i,1,n){
		dfs(i);
		for(auto it:S)
		adj[i].insert(it);
		S.clear();
	}
	int mx=-1;
	f(i,1,n){
		mx=max(mx,(int)adj[i].size());
	}
	++mx;
	cout<<mx<<'\n';
}
int main()
{	Fast;
//	int t;cin>>t;
//	while(t--)
	solve();
}