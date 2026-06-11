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
    dsu d(n);
    int t, u, v;
    rep(i, q) {
        cin >> t >> u >> v;
        if(t) {
            printf("%d\n", d.same(u, v));
        } else {
            d.merge(u, v);
        }
    }

    return 0;
}