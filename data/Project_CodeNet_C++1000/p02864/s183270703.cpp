// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k; cin >> n >> k;
    vll h(n + 1, 0); REP(i, n) cin >> h[i + 1];
    vvll dp(n + 1,  vll(n - k + 1,  HIGHINF));  // dp[i][j]: 左から見ていって i 個目を残す時に j 個ある時の最小コスト
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, min(i + 1, n - k + 1)) {
            ll tmp = HIGHINF;
            REP(k, i) {
                chmin(tmp, dp[k][j - 1] + max(h[i] - h[k], 0LL));
            }
            dp[i][j] = tmp;
        }
    }
    
    ll ans = HIGHINF;
    REP(i, n + 1) chmin(ans, dp[i][n - k]);
    cout << ans << '\n';
    return 0;
}
