#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define frr(j,i,n) for(int i=j;i<=n;++i)
using namespace std;
vector<int> g[100005];
int vis[100005];
void dfs(int node)
{
    vis[node]++;
    for(int child : g[node])
    {
        if(!vis[child])
            dfs(child);
    }
}
void solve() 
{
	int n,m;
    cin>>n>>m;
    int u,v;
    frr(1,i,m)
    {
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cnt=0;
    frr(1,i,n)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt-1;

}
int main() 
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--)
	solve();
	return 0;
}

