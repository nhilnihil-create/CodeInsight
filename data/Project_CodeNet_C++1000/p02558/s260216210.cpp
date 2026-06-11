#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main() {
    int N, Q;  cin >> N >> Q;
    dsu d(N);
    for (int i = 0; i < Q; ++i) {
        int t, u, v;  cin >> t >> u >> v;
        if (t == 0) d.merge(u, v);
        else cout << d.same(u, v) << endl;
    }
}
