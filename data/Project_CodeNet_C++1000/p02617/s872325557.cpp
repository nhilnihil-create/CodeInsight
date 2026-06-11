#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5+5;
int n, p[N];
vector<int> adj[N];

void dfs(int v, int u) {
    p[v] = u;
    for(int w : adj[v]) {
        if(w == u)  continue;
        dfs(w, v);
    }
}

main() {
    // freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    int x = n*(n+1)/2;
    for(int i=1; i<=n; i++) {
        x += ((i-1)*i + (n-i)*(n-i+1))/2 * (adj[i].size()-1);
        if(i > 1) {
            int l = min(p[i], i),
                r = max(p[i], i);
            x -= (l*(l-1) + (n-r)*(n-r+1) + (r-l)*(r-l-1))/2;
        }
    }
    cout << x;
}