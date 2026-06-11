#include <bits/stdc++.h>
#include <atcoder/fenwicktree.hpp>
using namespace std;
using namespace atcoder;

//#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
using intmap = map<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
inline bool bit (ll b, ll i) { return b & (1 << i); }
inline ll ceiv (ll a, ll b) { return (a + b - 1) / b; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define debug(x) cerr << #x << ": " << x << '\n'
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()

signed main() {
    int n, Q;
    cin >> n >> Q;
    
    fenwick_tree<ll> fw(n);
    rep(i,n){
        int a; cin >> a;
        fw.add(i, a);
    }
    
    while(Q--){
        int type; cin >> type;
        if(type == 0){
            int p, x;
            cin >> p >> x;
            fw.add(p, x);
        }else{
            int l, r;
            cin >> l >> r;
            cout << fw.sum(l, r) << endl;
        }
    }
}