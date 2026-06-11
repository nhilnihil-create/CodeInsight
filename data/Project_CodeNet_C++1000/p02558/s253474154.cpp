#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;
using namespace atcoder;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int N,Q;
    cin >> N >> Q;
    dsu d(N);
    rep (i, Q) {
        int t,u,v;
        cin >> t >> u >> v;
        if (t == 0) {
            d.merge(u, v);
        }
        else {
            if (d.same(u, v)) {
                cout << 1 << endl;
            }
            else {
                cout  << 0 << endl;
            }
        }
    } 
    return 0;
}