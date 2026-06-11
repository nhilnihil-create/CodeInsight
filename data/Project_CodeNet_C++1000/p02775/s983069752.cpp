#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;

    string N;
    cin >> N;

    ll L = SZ(N);

    vector<vector<ll>> dp(L + 5, vector<ll>(2, 0));
    dp[0][1] = 1;

    rep(i, L) {
        ll n = N[i] - '0';
        dp[i + 1][0] = min(dp[i][0] + n, dp[i][1] + (10 - n));
        dp[i + 1][1] = min(dp[i][0] + n + 1, dp[i][1] + (10 - n - 1));
    }

    // rep(i, L + 2) { cout << dp[i][1] << " "; }
    // cout << endl;
    // rep(i, L + 2) { cout << dp[i][0] << " "; }
    // cout << endl;

    cout << dp[L][0] << endl;

    return 0;
}
