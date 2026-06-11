#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main(){
    int n, q; cin >> n >> q;
    dsu data(n);
    while (q--) {
        int t, u, v; cin >> t >> u >> v;
        if (t) cout << (data.same(u,v) ? 1 : 0) << "\n";
        else data.merge(u,v);
    }
    return 0;
}