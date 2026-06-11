#include <bits/stdc++.h>

#define ll long long int

const ll mod=1e9+7;

using namespace std;

ll dfs(ll k, vector<vector<ll>> const & graph, ll now, ll from) {
    ll can_use_color_num;
    if (from == -1) {
        can_use_color_num = k - 1;
    } else {
        can_use_color_num = k - 2;
    }

    if (k < graph[now].size()) return 0;

    ll case_num = 1;

    for (auto e : graph[now]) {
        if (e == from) continue;

        case_num *= can_use_color_num;
        can_use_color_num--;
        case_num %= mod;
    }

    for (auto e: graph[now]) {
        if (e == from) continue;

        case_num *= dfs(k, graph, e, now);
        case_num %= mod;
    }

    return case_num;
}

int main() {
    ll n, k;
    cin >>n >>k;

    vector<vector<ll>> graph(n);

    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ll res = k*dfs(k, graph, 0, -1);
    res %= mod;
    cout << res << endl;
    return 0;   
}
