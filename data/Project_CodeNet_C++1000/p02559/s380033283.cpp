#include <atcoder/fenwicktree.hpp>
#include <iostream>

#define rep(i, n) for (int i = 0; i < n; ++i)

using ll = long long;
using namespace std;
using namespace atcoder;

int main(void) {
    int n, q;
    cin >> n >> q;

    fenwick_tree<ll> bit(n);

    rep(i, n) {
        ll val;
        cin >> val;
        bit.add(i, val);
    }

    rep(loop, q) {
        int t;
        cin >> t;
        if (t) {
            ll l, r;
            cin >> l >> r;
            cout << bit.sum(l, r) << endl;
        } else {
            ll p, x;
            cin >> p >> x;
            bit.add(p, x);
        }
    }

    return 0;
}