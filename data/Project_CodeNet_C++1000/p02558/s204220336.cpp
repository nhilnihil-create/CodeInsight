#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int N, Q;
    cin >> N >> Q;
    dsu d(N);
    rep(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            cout << d.same(u, v) ? 1 : 0;
            cout << endl;
        }
    }
}