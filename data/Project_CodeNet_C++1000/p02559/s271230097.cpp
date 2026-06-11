#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll e() { return 0; }

int main() {
    ll N, Q;  cin >> N >> Q;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) cin >> A[i];
    segtree<ll, op, e> seg(A);

    for (ll _ = 0; _ < Q; ++_) {
        ll q;  cin >> q;
        if (q == 0) {
            ll p, x;  cin >> p >> x;
            seg.set(p, seg.get(p) + x);
        }
        else if (q == 1) {
            ll l, r;  cin >> l >> r;
            cout << seg.prod(l, r) << endl;
        }
    }
}
