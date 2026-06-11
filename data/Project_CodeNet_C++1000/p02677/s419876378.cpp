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
    double A, B, H, M;
    cin >> A >> B >> H >> M;

    double h_deg = 0.5 * M + 30.0 * H;
    double m_deg = 6.0 * M;

    double deg = min(abs(h_deg - m_deg), 360.0 - abs(h_deg - m_deg));
    // cout << deg << endl;

    double ans = sqrt(A * A + B * B - 2 * A * B * cos(deg * (M_PI / 180.0)));

    cout << fixed << setprecision(20) << ans << endl;

    return 0;
}