#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    auto g = atcoder::dsu(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << (g.same(u, v) ? 1 : 0) << endl;
        } else {
            g.merge(u, v);
        }
    }
}