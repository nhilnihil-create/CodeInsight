#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 1e5 + 5;
vector<vector<pair<int,int>>> adj;
int vis[N];
int col[N];
void dfs(int v , int skip){
    vis[v] = 1;
    int c = 1;
    for(int i = 0; i<sz(adj[v]); i++){
        if(vis[adj[v][i].fi]){
            continue;
        }
        if(c == skip){
            c++;
        }
        col[adj[v][i].se] = c;
        dfs(adj[v][i].fi,c);
        c++;
    }
}
int main() {    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        vector<pair<int,int>> v;
        adj.pb(v);
    }
    for(int i = 0; i<n-1; i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].pb({v,i});
        adj[v].pb({u,i});
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = max(ans , sz(adj[i]));
    }
    cout<<ans<<"\n";
    dfs(0,-1);
    for(int i = 0; i<n-1; i++){
        cout<<col[i]<<"\n";
    }

}