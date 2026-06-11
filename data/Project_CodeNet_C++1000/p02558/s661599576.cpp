// URL : https://atcoder.jp/contests/practice2/tasks/practice2_a
#include <atcoder/all>
using namespace atcoder;
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

signed main() {
    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    while (Q--) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            d.merge(u, v);
        else
            cout << d.same(u, v) << endl;
    }
}
