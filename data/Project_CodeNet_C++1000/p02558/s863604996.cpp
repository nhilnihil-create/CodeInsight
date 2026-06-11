#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, Q;
    cin >> N >> Q;
    dsu D(N);
    for (int i = 0; i < Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t) cout << D.same(u, v) << "\n";
        else D.merge(u, v);
    }
}