#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
const ul mod = 1000000007;

struct edge {
    ll to, cost;
    edge(ll to = 0, ll cost = 0) : to(to), cost(cost) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> p(n), c(n);
    rep(i, n) {
        cin >> p[i];
        p[i]--;
    }
    rep(i, n) { cin >> c[i]; }
    ll cost_max = c[0];
    rep(i, n) { cost_max = max(cost_max, c[i]); }
    if (cost_max < 0) {
        cout << cost_max << endl;
        return 0;
    }

    vector<edge> g(n);
    rep(i, n) { g[i] = edge(p[i], c[p[i]]); }

    vector<bool> seen(n);
    vector<ll> cost(n), length(n);
    auto dfs_first = [&](auto self, size_t x, ll start, ll depth) -> ll {
        seen[x] = true;
        if (g[x].to == start) {
            length[g[x].to] = depth + 1;
            return g[x].cost;
        } else {
            return self(self, g[x].to, start, depth + 1) + g[x].cost;
        }
    };

    auto dfs_second = [&](auto self, size_t x, ll value, ll depth) -> void {
        cost[x] = value;
        length[g[x].to] = depth;
        if (cost[g[x].to] == value) {
            return;
        } else {
            self(self, g[x].to, value, depth);
        }
    };

    rep(i, n) {
        if (!seen[i]) {
            ll value = dfs_first(dfs_first, i, i, 0);
            dfs_second(dfs_second, i, value, length[i]);
        }
    }

    auto dfs = [&](auto self, size_t x, ll remain) -> ll {
        if (remain == 0) {
            return 0;
        } else {
            return max(0LL, self(self, g[x].to, remain - 1) + g[x].cost);
        }
    };

    vector<ll> ans(n);
    rep(i, n) {
        ll temp = 0;
        if (cost[i] > 0) {
            temp = cost[i] * (k / length[i] - 1);
        }
        ans[i] = temp + dfs(dfs, i, k % length[i] + length[i]);
    };

    ll temp = ans[0];
    rep(i, n) { temp = max(temp, ans[i]); }
    cout << temp << endl;
    return 0;
}

