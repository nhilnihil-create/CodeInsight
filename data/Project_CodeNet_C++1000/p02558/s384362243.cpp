#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using namespace atcoder;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

signed main(){
    ll N, Q;
    cin >> N >> Q;
    dsu uf(N);
    ll t, u, v;
    REP(i, Q){
        cin >> t >> u >> v;
        if(t == 0) uf.merge(u, v);
        else PRINT(uf.same(u, v));
    }
    return 0;
}