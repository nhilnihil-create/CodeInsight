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
int S=0;
void dfs(int s){
	vis[s]=1;
	for(auto  it:adj[s]){
		if(!vis[it]){
			++S;
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
	int mx=-1;
	f(i,1,n){
		dfs(i);
		mx=max(S,mx);
		S=0;
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