#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define int long long int
const int mod = 1000000007;
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

vector<int>adj[200005];
bool vis[200005];


int cnt;

void dfs(int u){
    cnt++;
    vis[u] = true;
    for(auto i : adj[u]){
        if(!vis[i]){
            dfs(i);
        }
    }
    return;
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            v.push_back(cnt);
        }
    }
    int ans = 0;
    for(int i=0; i<v.size(); i++){
        ans = max(ans, v[i]);
    }
    cout<<ans<<endl;
    return 0;
}