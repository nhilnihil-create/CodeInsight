#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int N, Q;
    cin >> N >> Q;
    atcoder::dsu d(N);
    for (int z = 0; z < Q; z++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        }else {
            cout << (d.same(u, v) ? 1 : 0) << "\n";
        }
    }
}