#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int n, q; cin >> n >> q;
    dsu uf(n);
    while (q--) {
        int t; cin >> t;
        int u, v; cin >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            cout << uf.same(u, v) << endl;
        }
    }
}