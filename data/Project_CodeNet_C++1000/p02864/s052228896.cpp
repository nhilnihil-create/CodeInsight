#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n, k, h[301];
    cin >> n >> k;
    rep(i, n) cin >> h[i + 1];

    ll dp[309][309];
    rep(i, 309) rep(j, 309) dp[i][j] = 1LL << 60;
    dp[0][0] = 0;
    ll ans = 1e18;
    FOR(i, 1, n + 1)
    FOR(j, 1, n + 1)
    rep(l, i) chmin(dp[i][j], dp[l][j - 1] + max(0ll, h[i] - h[l]));

    rep(i, n + 1) chmin(ans, dp[i][n - k]);
    cout << ans << endl;
}