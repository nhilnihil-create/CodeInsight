#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll ans = 1;
vector<vector<pair<ll, ll>>> edges; //{node: {node1, index1}, {node2, index2}}
vll colors;

void dfs(ll node, ll color, ll pre) {
    ll new_color = 0;
    if (color == 0) new_color = 1;

    for (auto e : edges[node]) {
        if (e.first == pre) continue;

        if (ans < edges[node].size()) ans = edges[node].size();
        colors[e.second] = new_color;
        dfs(e.first, new_color, node);
        new_color++;
        if (new_color == color) new_color++;
    }
}

int main()
{
    ll N; cin >> N;
    colors.resize(N - 1, -1);
    edges.resize(N);
    rep(i, N - 1) {
        ll a, b; cin >> a >> b; a--, b--;
        edges[a].push_back({b, i});
        edges[b].push_back({a, i});
    }

    dfs(0, -1, -1);
    cout << ans << endl;
    rep(i, N - 1) cout << colors[i] + 1 << endl;
    return 0;
}