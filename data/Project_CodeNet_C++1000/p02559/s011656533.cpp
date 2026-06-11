#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/fenwicktree>
using namespace atcoder;

int main() {
    ll N, Q;
    cin >> N >> Q;

    fenwick_tree<ll> ft(N);
    rep(i, N) {
        ll a;
        cin >> a;
        ft.add(i, a);
    }

    rep(i,Q) {
        ll t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            ft.add(x, y);
        } else {
            cout << ft.sum(x, y) << endl;
        }
    }
    return 0;
}