#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N, Q; cin >> N >> Q;
    dsu d(N);
    rep(i, Q) {
        int t, u, v; cin >> t >> u >> v;
        if (t) {
            if (d.same(u, v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else {
            d.merge(u, v);
        }
    }
}
