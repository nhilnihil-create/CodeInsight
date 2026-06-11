#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N;
vector<int> G[100100];
vector<P> edges;
map<int, int> mp;
int K = 0;

void dfs(int v, int pv, int pc) {
    int c = 1;
    rep(i, G[v].size()) {
        int nv = G[v][i];
        if (nv==pv) continue;
        if (c==pc) c++;
        mp[1000000*min(v, nv)+max(v, nv)] = c;
        K = max(c, K);
        dfs(nv, v, c);
        c++;
    }
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N-1) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
        edges.pb(P(a-1, b-1));
    }
    
    dfs(0, -1, -1);
    cout << K << endl;
    rep(i, N-1) {
        int a = edges[i].first, b = edges[i].second;
        cout << mp[1000000*a+b] << endl;
    }
}