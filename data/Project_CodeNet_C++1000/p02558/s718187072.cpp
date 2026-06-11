#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

#include <atcoder/dsu>
using namespace atcoder;

int main() {
    int N, Q;
    cin >> N >> Q;
    dsu uf(N);
    rep(i,Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) {
            uf.merge(u, v);
        } else {
            if (uf.same(u, v)) {
                cout << 1 << endl;
            } else {
                cout << 0 << endl;
            }
        }
        
    }
    return 0;
}