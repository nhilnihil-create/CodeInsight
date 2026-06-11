#include <bits/stdc++.h>

#include <atcoder/all>
typedef long long lint;
using namespace std;
using namespace atcoder;

int main() {
    int n, q;
    cin >> n >> q;
    dsu d(n);
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v;
            cin >> u >> v;
            d.merge(u, v);
        } else {
            int u, v;
            cin >> u >> v;
            int ans = d.same(u, v) ? 1 : 0;
            cout << ans << endl;
        }
    }
}