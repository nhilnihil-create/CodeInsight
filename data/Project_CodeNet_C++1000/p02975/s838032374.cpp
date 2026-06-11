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

    ll N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    map<ll, ll> cnt;
    rep(i, N) { cnt[a[i]]++; }

    if (SZ(cnt) == 1) {
        auto it = cnt.begin();
        if (it->first != 0) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
        return 0;
    } else if (SZ(cnt) == 2) {
        bool flg = true;
        for (auto e : cnt) {
            if (!((e.second == N / 3 && e.first == 0) ||
                  (e.second == 2 * N / 3)))
                flg = false;
        }

        if (flg) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    } else if (SZ(cnt) == 3) {
        vector<ll> b(3);
        ll i = 0;

        bool flg = true;
        for (auto e : cnt) {
            if (e.second == N / 3) {
                b[i] = e.first;
            } else {
                cout << "No" << endl;
                return 0;
            }
            i++;
        }
        // cout << b[0] << "," << b[1] << "," << b[2] << endl;
        // cout << (b[0] ^ b[1] ^ b[2]) << endl;
        // cout << (b[0] ^ b[1] ^ b[2] == 0) << endl;

        if ((b[0] ^ b[1] ^ b[2]) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (SZ(cnt) > 3) {
        cout << "No" << endl;
        return 0;
    }

    return 0;
}