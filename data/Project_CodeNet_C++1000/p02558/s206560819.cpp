#include <atcoder/dsu>
#include <iostream>

#define rep(i, n) for (int i = 0; i < n; ++i)

using namespace std;
using namespace atcoder;

int main(void) {
    int n, q;
    cin >> n >> q;

    dsu uf(n);

    rep(loop, q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) {
            cout << uf.same(u, v) << endl;
        } else {
            uf.merge(u, v);
        }
    }

    return 0;
}