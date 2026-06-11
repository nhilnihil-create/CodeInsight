#include <bits/stdc++.h>
#include <algorithm>
// #include <atcoder/all>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define REP2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define rep(i, n) REP(i, 0, n)
#define rep2(i, n) REP2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define rall(hoge) (hoge).rbegin(), (hoge).rend()
#define en '\n'
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> inline void print(T x) { cout << x << '\n'; }
template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    vl a(n),f(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> f[i];
    sort(all(a));
    sort(all(f),greater<ll>());

    auto isok = [&](ll x) {
        ll cnt = 0;
        rep(i,n) {
            if(a[i]*f[i] <= x) continue;
            cnt += (a[i]-x/f[i]);
            if (cnt > k) return 0;
        }
        return 1;
    };

    ll ok = (ll)1e18 + 1;
    ll ng = -1;
    while (ok-ng > 1) {
        ll mid = (ok+ng)/2;
        if (isok(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }

    }
    print(ok);
    return 0;
}
