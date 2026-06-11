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
#ifdef DEBUG_ 
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
const ll INF = 1LL<<60;

// ans[i] = (i番目の頂点v, swapできる頂点をまとめたときにvが何番目か)
vector<PII> tsort(vector<vector<ll>> g) {
    const int n = g.size();
    vector<ll> h(n);
    REP(i, n) for(int j: g[i]) h[j]++;

    stack<PII> st;
    REP(i, n) if(h[i] == 0) st.push({i, 0});

    vector<PII> ans;
    while(st.size()) {
        PII p = st.top(); st.pop();
        ans.push_back(p);
        for(auto& j: g[p.first]) {
            h[j]--;
            if(h[j] == 0) st.push({j, p.second+1});
        }
    }

    return ans;
}

signed main(void) {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    REP(i, m) {
        ll u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    auto ans = tsort(g);
    for(auto p: ans) cout << p.first << endl;

    return 0;
}
