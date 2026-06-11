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

vector<vector<pair<ll, ll>>> G;
vll colors;
ll max_color = 0;

void dfs(ll node, ll color, ll pre) {
    ll new_color = 0;
    if (color == 0) new_color++;

    max_color = max(max_color, (ll)G[node].size());
    for (auto next_node : G[node]) {
        if (next_node.first == pre) continue;
        colors[next_node.second] = new_color;
        dfs(next_node.first, new_color, node);
        new_color++;
        if (new_color == color) new_color++;
    }
}



int main()
{
    ll N; cin >> N;
    G.resize(N);
    colors.resize(N - 1, -1);
    rep(i, N - 1) {
        ll a, b; cin >> a >> b; a--; b--;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }

    dfs(0, -1, -1); // node to proceed, color cannot be used, previous node
    cout << max_color << endl;
    rep(i, N - 1) {
        cout << colors[i] + 1 << endl;
    }
    return 0;
}