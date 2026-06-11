#include <bits/stdc++.h>
#include <atcoder/all>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;
using namespace atcoder;

signed main(){
    ll N, Q, a;
    cin >> N >> Q;
    fenwick_tree<ll> bit(N);
    REP(i, N){
        cin >> a;
        bit.add(i, a);
    }    
    ll q, l, r;
    REP(i, Q){
        cin >> q >> l >> r;
        if(q == 0) bit.add(l, r);
        else PRINT(bit.sum(l, r));
    }
    return 0;
}