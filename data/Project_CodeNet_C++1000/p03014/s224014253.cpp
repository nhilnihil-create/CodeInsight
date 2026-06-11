#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
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
    ll H, W;
    cin >> H >> W;

    vector<string> S(H);
    rep(i, H) cin >> S[i];

    vector<vector<ll>> cntX(H, vector<ll>(W, 0));
    vector<vector<ll>> cntY(H, vector<ll>(W, 0));

    rep(i, H) {
        ll cnt = 0;
        rep(j, W) {
            if (S[i][j] == '#')
                cnt = 0;
            else
                cnt++;
            cntX[i][j] = cnt;
        }
    }

    repr(i, H - 1) {
        ll max_cnt = 0;
        repr(j, W - 1) {
            if (S[i][j] == '#')
                max_cnt = 0;
            else
                chmax(max_cnt, cntX[i][j]);
            cntX[i][j] = max_cnt;
        }
    }

    // rep(i, H) {
    //     rep(j, W) { cout << cntX[i][j] << " "; }
    //     cout << endl;
    // }

    rep(i, W) {
        ll cnt = 0;
        rep(j, H) {
            if (S[j][i] == '#')
                cnt = 0;
            else
                cnt++;
            cntY[j][i] = cnt;
        }
    }

    repr(i, W - 1) {
        ll max_cnt = 0;
        repr(j, H - 1) {
            if (S[j][i] == '#')
                max_cnt = 0;
            else
                chmax(max_cnt, cntY[j][i]);
            cntY[j][i] = max_cnt;
        }
    }

    // cout << "---" << endl;
    // rep(i, H) {
    //     rep(j, W) { cout << cntY[i][j] << " "; }
    //     cout << endl;
    // }

    ll ans = 0;
    rep(i, H) {
        rep(j, W) { chmax(ans, cntX[i][j] + cntY[i][j] - 1); }
    }
    cout << ans << endl;

    return 0;
}