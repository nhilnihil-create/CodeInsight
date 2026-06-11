#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

void solve(){
    int n, m, s, t;
    cin >> n >> m;
    v2<int> adj(n);
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
    }
    cin >> s >> t;
    --s, --t;

    queue<pair<int, int>> q;
    v2<int> dist = fill(n, 3, -1);
    q.push({s, 0});
    dist[s][0] = 0;
    while(!q.empty()){
        int node = q.front().F;
        int mod = q.front().S;
        q.pop();
        int nextmod = (mod+1)%3;
        for(int nextnode : adj[node]){
            if(dist[nextnode][nextmod]==-1){
                dist[nextnode][nextmod] = 1+dist[node][mod];
                q.push({nextnode, nextmod});
            }
        }
    }

    if(dist[t][0]!=-1){
        cout << dist[t][0]/3 << "\n";
    }
    else{
        cout << "-1\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}