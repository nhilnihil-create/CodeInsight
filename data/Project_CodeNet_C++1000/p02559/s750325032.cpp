#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;

// Binary Index Treeは長さnの数列に対して
// 1. 区間[a,b)にxを加算する
// 2. 区間[a,b)の総和を求める
// という操作をO(log(n))で処理できる
 
// 区間加算にも対応したBinary Index Tree(1-indexで使うことに気をつける)
template <class Abel> struct BIT {
    
    vector<Abel> dat[2];
    Abel UNITY_SUM = 0;
    
    BIT(ll n) { 
        init(n);
    }
 
    void init(ll n) { 
        for(ll iter = 0; iter < 2; ++iter) {
            dat[iter].assign(n+1, UNITY_SUM); 
        }
    }
    
    inline void sub_add(ll p, ll a, Abel x) {
        for(ll i = a; i < (ll)dat[p].size(); i += i & -i) {
            dat[p][i] = dat[p][i] + x;
        }
    }

    inline Abel sub_sum(ll p, ll a) {
        Abel res = UNITY_SUM;
        for(ll i = a; i > 0; i -= i & -i) {
            res = res + dat[p][i];
        } 
        return res;
    }

    // 区間[a,b)にxを加算する(a,bは1-index)
    inline void add(ll a, ll b, Abel x) {
        sub_add(0, a, x * -(a - 1)); 
        sub_add(1, a, x);
        sub_add(0, b, x * (b - 1));
        sub_add(1, b, x * (-1));
    }
    
    // 区間[a,b)の総和を計算する(a,bは1-index)
    inline Abel getsum(ll a, ll b) {
        return sub_sum(0, b - 1) + sub_sum(1, b - 1) * (b - 1) - sub_sum(0, a - 1) - sub_sum(1, a - 1) * (a - 1);
    }
};

int main() {
    ll n, q;
    cin >> n >> q;

    vl a(n+1);
    exrep(i, 1, n) {
        cin >> a[i];
    }

    BIT<ll> biT(n+10);
    exrep(i, 1, n) {
        biT.add(i, i+1, a[i]);  // biT[i]をa[i]で初期化
    }

    rep(i, q) {
        ll t;
        cin >> t;
        if(t == 0) {
            ll p, x;
            cin >> p >> x;
            p++;  // pを1-indexにする 
            biT.add(p, p+1, x);
        }
        else if(t == 1) {
            ll L, R;
            cin >> L >> R;
            L++;  R++;  // L,Rを1-indexにする
            out(biT.getsum(L, R)); 
        }
    }
    
    re0;
}