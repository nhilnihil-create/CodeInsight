#include <bits/stdc++.h>
#include <atcoder/all>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using namespace atcoder;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    fenwick_tree<ll> fw(n);
    int a;
    rep(i, n) {
        cin >> a;
        fw.add(i, a);
    }
    int s, l, r;
    rep(i, q) {
        cin >> s >> l >> r;
        if(s) {
            printf("%lld\n", fw.sum(l, r));
        } else {
            fw.add(l, r);
        }
    }

    return 0;
}