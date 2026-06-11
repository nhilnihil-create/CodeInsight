#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> g[100100];

ll K = 0;
map<P, ll> mp; // 辺の色を保持

// 探索する頂点、親の色
void dfs(int cur, int par_color, int par = -1) {
    int color = 1;
    for (int i = 0; i < g[cur].size(); i++) {
        int next = g[cur][i]; 

        if (par == next) continue;

        if (par_color == color) color++;

        if (cur > next) {
            mp[P(next, cur)] = color;
        } else {
            mp[P(cur, next)] = color;
        }
        color++;
        // cout << "cur " << cur << " " << "next " << next << " color " << color << endl; 
        dfs(next, color - 1, cur);
    }
}

int main() {
    cin >> N;

    vector<P> v;
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);

        if (a > b) swap(b, a);
        v.push_back(P(a, b));
    }

    rep(i, N) {
        K = max(K, (ll)g[i].size());
    }
    cout << K << endl;

    dfs(0, 0);

    rep(i, v.size()) {
        // cout << v[i].first << " " << v[i].second << endl;
        cout << mp[v[i]] << endl;
    }
}