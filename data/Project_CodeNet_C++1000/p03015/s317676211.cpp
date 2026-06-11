//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("avx,avx2,fma")


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define pb push_back
#define F first
#define S second
#define ins insert
//#define mp make_pair
#define fo(i, n1, n, x) for(int i = n1; i <= n; i += x)
#define foo(i, n, n1, x) for(int i = n; i >= n1; i -= x)
#define bit __builtin_popcount
#define md (l + ((r - l) / 2))
#define all(x) x.begin(),x.end()
#define eb emplace_back
#define ub upper_bound
#define lb lower_bound
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file(s) if (fopen(s".in", "r")) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;


using ll = long long;

#define int ll


const int N = 1e5+33, mod = 1e9 + 7, mod2 = 998244353;
const int MAX = 1e5 + 11;
const int INF1 = 2e9 + 11;
const ll INF2 = 2e18 + 11;
const double INF3 = 1e8 + 11;
const int base = 500;
const int P = 31;
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
const double EPS = 1e-4;
const double PI = acos(-1.0);


template<typename T> using ordered_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }


typedef pair <int, int> pii;        // #include <ext/pb_ds/assoc_container.hpp>
typedef pair <ll, ll> pll;         // #include <ext/pb_ds/tree_policy.hpp>
typedef vector <int> vi;          // #include <ext/rope>
bool prime(int n) {
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){return 0;}
    }return 1;}
#define endl '\n'
ll pw[N];

void solve() {
    pw[0] = 1;
    for(int i = 1; i < N; i ++) {
        pw[i] = pw[i-1] * 3ll % mod;
    }
    string s;
    cin >> s;
    reverse(all(s));
    vi v;
    for(int i = 0; i < s.size(); i ++) {
        if(s[i] == '1') {
            v.pb(i);
        }
    }
    int cnt = v.size() - 1;
    ll ans = 0;
    ll cur = 1;
    while(~cnt) {
        ans += cur * pw[v[cnt--]] % mod;
        ans %= mod;
        cur <<= 1ll;
        cur %= mod;
    }
    ans += cur;
    ans %= mod;
    cout << ans;
}
/*
101
    dp[i] = dp[i-1] + bp(2ll , bit(i));

110000000
011000000
001110000
000001111
5 3
3 2 2

2 4 1

_ _ _ _ _
1 1 1
  2 2 3 3

*/

main() {
    ios;
    int tt = 1;
//    cin >> tt;
    while(tt --) {
        solve();
//        brute();
    }
    return 0;
}
