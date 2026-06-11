#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

int main() {
    ll N, Q;  cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    for (ll i = 0; i < N; ++i) {
        ll a;  cin >> a;
        fw.add(i, a);
    }

    for (ll _ = 0; _ < Q; ++_) {
        ll q;  cin >> q;
        if (q == 0) {
            ll p, x;  cin >> p >> x;
            fw.add(p, x);
        }
        else if (q == 1) {
            ll l, r;  cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}
