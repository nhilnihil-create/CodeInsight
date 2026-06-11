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
    ll N, M;
    cin >> N >> M;
    vector<ll> s(M), c(M);
    rep(i, M) cin >> s[i] >> c[i];

    vector<vector<ll>> buf(N);
    rep(i, M) {
        s[i]--;
        buf[s[i]].pb(c[i]);
    }

    rep(i, N) { buf[i].erase(unique(ALL(buf[i])), buf[i].end()); }

    // rep(i, N) {
    //     repv(buf[i]) cout << *it << " ";
    //     cout << endl;
    // }

    if (N == 1) {
        if (M == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (SZ(buf[0]) == 1) {
            cout << buf[0][0] << endl;
            return 0;
        }
    }

    string str;
    rep(i, N) {
        if (SZ(buf[i]) >= 2) {
            cout << -1 << endl;
            return 0;
        } else if (SZ(buf[i]) == 1) {
            if (buf[i][0] == 0 && i == 0) {
                cout << -1 << endl;
                return 0;
            }
            str.pb(char(buf[i][0] + '0'));
        } else if (SZ(buf[i]) == 0) {
            if (i == 0) {
                str.pb('1');
            } else {
                str.pb('0');
            }
        }
    }

    cout << str << endl;

    return 0;
}