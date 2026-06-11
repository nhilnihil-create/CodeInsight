#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define REP2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define rep(i, n) REP(i, 0, n)
#define rep2(i, n) REP2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<ll, ll> pll;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
const int MOD = 1000000007;
// constexpr long long MOD = (ll)1e9 + 7;
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

// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(k+1, 0)));


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x;
    cin >> x;
    ll t = 0;
    ll res = 0;
    rep(i,1000) {
        t += x;
        res++;
        if (t%360 == 0) break;
    }
    print(res);

    return 0;
}
