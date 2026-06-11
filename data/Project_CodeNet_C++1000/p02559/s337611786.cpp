#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define debugbit(x, n) cerr << #x << " = " << bitset<n>(x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define debugbit(x, n)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;


signed main(){
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    rep(i,0,N) cin >> a[i];
    atcoder::fenwick_tree<ll> ft(N); // binary index tree
    rep(i,0,N) ft.add(i, a[i]);
    rep(qi,0,Q) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            ft.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.sum(l, r) << endl;
        }
    }

    return 0;
}
