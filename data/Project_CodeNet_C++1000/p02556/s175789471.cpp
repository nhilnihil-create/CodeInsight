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
long long powmod(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> x(n),y(n);
    rep(i,n) {
        ll a,b;
        cin >> a >> b;
        x[i] = a-b;
        y[i] = a+b;
    }

    sort(all(x));
    sort(all(y));
    print(max(x.back()-x[0],y.back()-y[0]));
    return 0;
}
