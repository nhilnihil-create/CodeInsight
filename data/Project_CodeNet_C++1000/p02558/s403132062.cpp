#include <bits/stdc++.h>

#include "atcoder/dsu"
using namespace std;
typedef long long int ll;

int main(int, char **) {
    int n, q;
    cin >> n >> q;
    atcoder::dsu uf(n);
    for (int i = 0; i < q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            cout << (int)uf.same(u, v) << "\n";
        }
    }

    fflush(stdout);
}
