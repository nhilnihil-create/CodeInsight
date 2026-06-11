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
    ll N, K;
    cin >> N >> K;

    vector<ll> p(N);
    rep(i, N) cin >> p[i];

    double ans = 0;
    vector<double> e(N, 0);
    rep(i, N) {
        e[i] = ((double)(1.0 + p[i]) * p[i] / 2.0) * (1.0 / (double)p[i]);
    }

    vector<double> sum(N, 0);
    rep(i, K) { sum[0] += e[i]; }
    reps(i, K, N) { sum[i - K + 1] = sum[i - K] + e[i] - e[i - K]; }

    // rep(i, N) { cout << e[i] << " "; }
    // cout << endl;

    // rep(i, N) { cout << sum[i] << " "; }
    // cout << endl;

    rep(i, N) { chmax(ans, sum[i]); }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}