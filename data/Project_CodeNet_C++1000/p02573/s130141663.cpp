#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;
vector<long long> g[N];
set<pair<long long, long long> > CheckAgain;
set<long long> vis;

long long dfs(long long node) {
    if(vis.count(node))
        return 0;
    vis.insert(node);
    long long ans = 1;
    for(long long i = 0; i < g[node].size(); i++) {
        ans += dfs(g[node][i]);
    }
    return ans;
}

int main() {
 	long long n, m;
 	cin >> n >> m;
 	for(long long i = 1; i <= m; i++) {
        long long u, v;
        cin >> u >> v;
        if(CheckAgain.count({u, v}) || CheckAgain.count({v, u}))
            continue;
        g[u].push_back(v);
        g[v].push_back(u);
 	}
 	long long ans = 0;
 	for(long long i = 1; i <= n; i++) {
        if(!vis.count(i))
            ans = max(ans, dfs(i));
 	}
 	cout << ans << endl;
}
