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

ll score(char c, ll R, ll S, ll P) {
    if (c == 'r') {
        return R;
    } else if (c == 's') {
        return S;
    } else if (c == 'p') {
        return P;
    }
}

int main() {
    INIT;

    ll N, K, R, S, P;
    string T;
    cin >> N >> K >> R >> S >> P;
    cin >> T;

    string str = "";
    rep(i, SZ(T)) {
        if (T[i] == 's') {
            str += "r";
        } else if (T[i] == 'r') {
            str += "p";
        } else if (T[i] == 'p') {
            str += "s";
        }
    }

    // cout << str << endl;

    ll sum = 0;
    rep(i, SZ(str)) { sum += score(str[i], R, S, P); }
    // cout << sum << endl;

    rep(i, K) {
        string s = "";

        for (ll j = i; j < N; j += K) {
            // cout << str[j];
            s += str[j];
        }
        // cout << endl;

        reps(j, 1, SZ(s)) {
            if (s[j - 1] == s[j]) {
                sum -= score(s[j], R, S, P);
                s[j] = 'x';
            }
        }

        // cout << s << endl;
    }
    cout << sum << endl;

    // repv(cands) cout << *it << endl;

    return 0;
}