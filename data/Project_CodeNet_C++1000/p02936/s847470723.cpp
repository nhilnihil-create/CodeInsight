#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;

V<V<int> > g;
V<ll> ans;

void dfs(int v, int i = -1) {
    for(auto next_v : g[v]){
        if(next_v == i) continue;
        ans[next_v] += ans[v];
        dfs(next_v, v);
    }
}

int main() {
    int n, q; cin >> n >> q;
    g.resize(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans.resize(n);
    for(int i = 0; i < q; i++){
        int p, x; cin >> p >> x;
        p--;
        ans[p] += x;
    }

    dfs(0);

    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }



    return 0;
}
