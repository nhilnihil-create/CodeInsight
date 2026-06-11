#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

ll op(ll a, ll b) {
    return a + b;
}
ll e() {
    return 0;
}

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    segtree<ll, op, e> seg(a);
    rep(i, Q) {
        int q;
        cin >> q;
        if (q == 0) {
            ll p, x;
            cin >> p >> x;
            seg.set(p, seg.get(p) + x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
}