#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n, q;
    cin >> n >> q;
    dsu d(n);
    int t, u, v;
    rep(i, q) {
        cin >> t >> u >> v;
        if(t)
            cout << d.same(u,v) << endl;
        else
            d.merge(u, v);
    }
    return 0;
}