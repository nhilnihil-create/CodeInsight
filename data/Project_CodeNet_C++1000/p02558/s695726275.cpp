#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, m, n) for (int i = (m); i < (int)(n); i++)

int main() {
    int N, Q, t, u, v, res;
    cin >> N >> Q;
    dsu d(N);
    REP(i, Q) {
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        } else {
            res = d.same(u, v);
            cout << int(res) << endl;
        }
    }
}