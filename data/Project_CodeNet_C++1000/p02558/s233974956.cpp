
#include "bits/stdc++.h"
#include "atcoder/dsu"
using namespace std;
using namespace atcoder;
#define newl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
typedef long long ll;
#define int ll

int32_t main() {
    int n,q; cin >> n >> q;
    dsu d(n);
    while(q--) {
        int t, u, v; cin >> t >> u >> v;
        if(t == 0 ) {
            d.merge(u, v);
        } else if(t == 1) {
            cout << d.same(u, v) << newl;
        }
    }
    return 0;
}


