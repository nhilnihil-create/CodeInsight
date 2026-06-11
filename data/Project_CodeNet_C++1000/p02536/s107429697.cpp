#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(v) v.begin(), v.end()
#define mem(arr) memset(arr, 0, sizeof(arr))
#define ff first
#define ss second
#define int long long int
const int MOD = 1e9 + 7;
const int INF = 1e18;
const int N = 1e6 + 1;
vector<int> g[N];
vector<int> vis(N);
void dfs(int v){
    vis[v] = 1;
    for(int &u : g[v]){
        if(!vis[u]){
            dfs(u);
        }
    }
}
void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        g[i].clear();
    }
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    vis.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }
    cout << ans - 1 << '\n';
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    while(tc--){
        solve();
    }
}