#pragma GCC target("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>

#define f			first
#define sz(a)       ((int)(a).size())
#define s			second
#define all(v)		v.begin(),v.end()
#define pii 		pair<int,int>
#define vpii 		vector<pii>
#define eb			emplace_back
#define pb			push_back
#define fo(i,n)		for(int i=0;i<n;i++)
#define Fo(i,k,n)	for(int i=k;i<n;i++)
#define vi			vector<int>

using namespace std;
using ll  = long long;
using lld = long double;

const int oo = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int N = 1e5 + 2;
vi adj[N] , vis(N);
void dfs(int src){
    vis[src] = 1;
    for(int i : adj[src])
        if(!vis[i]) dfs(i);
}

signed main(){

#ifndef ONLINE_JUDGE
	//freopen("in.txt" , "r" , stdin);
#endif
	ios_base::sync_with_stdio(0);cin.tie(0);


    int n , m;
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++){
        int u , v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int ans =0;
    for(int i = 1 ; i <= n ;i++)
        if(!vis[i]) ans++ , dfs(i);
    
    cout << ans - 1 << '\n';
    return 0;

}

