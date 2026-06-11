#include"bits/stdc++.h"
#include<atcoder/fenwicktree.hpp>
using namespace atcoder;
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pll = pair<ll, ll>;
using tp3 = tuple<ll, ll, ll>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
// ============ template finished ============

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    rep(i, N)cin >> a[i];

    fenwick_tree<ll> fw(N);
    rep(i, N)fw.add(i, a[i]);
    rep(_, Q) {
        ll com;
        cin >> com;
        if (com == 0) {
            ll p, x;
            cin >> p >> x;
            fw.add(p, x);
        }
        else {
            ll l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
    return 0;
}
