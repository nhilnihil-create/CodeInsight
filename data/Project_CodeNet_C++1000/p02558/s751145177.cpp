#include <atcoder/dsu>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve() {
    ll N, Q;
    cin >> N >> Q;
    int t , u , v;
    atcoder::dsu d(N);
    vector<int> ans;
    for ( int i = 0; i < Q; i++ ) {
        cin >> t >> u >> v;
        if ( t == 0 ) {
            d.merge(u,v);
        } else {
            int x = d.same(u,v) ? 1 : 0;
            ans.push_back(x);
        }
    }
    for ( int i = 0; i < ans.size(); i++ ) {
        cout << ans[i] << "\n";
    }

    return 0;
}

int main() {
    solve();
    return 0;
}