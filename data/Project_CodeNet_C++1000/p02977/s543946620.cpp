#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

int main(void) {
    ll n;
    cin >> n;
    
    ll t = 1;
    while(t < n) t *= 2;
    if(t == n) {
        cout << "No\n";
        return 0;
    }

    vector<PII> edges;
    for(ll i=2; i+1<=n; i+=2) {
        edges.push_back({i, i+1});
        edges.push_back({i+1, 1});
        edges.push_back({1, n+i});
        edges.push_back({n+i, n+i+1});
    }
    edges.push_back({n+3, n+1});

    if(n%2==0) {
        ll t = 1;
        while(t < n) t *= 2;
        t /= 2;
        edges.push_back({t+n, 2*n});
        edges.push_back({n-t+1, n});
    }

    auto check = [&] {
        vector<vector<ll>> g(2*n+1);
        for(auto e: edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }

        bool ok;
        auto dfs = [&](auto &&self, ll v, ll p, ll st, ll w) -> void {
            // if(st == 1) dump(v, st, w);
            if(v == st+n) ok = st==w;
            for(auto to: g[v]) if(to!=p) {
                self(self, to, v, st, w^(to<=n ? to : to-n));
            }
        };
        vector<ll> err;
        FOR(i, 1, n+1) {
            dfs(dfs, i, -1, i, i);
            if(!ok) err.push_back(i);
        }
        if(err.size()) {
            dump(g);
            dump(err);
        }
    };
    // check();

    cout << "Yes\n";
    for(auto e: edges) cout << e.first << " " << e.second << "\n";

    return 0;
}