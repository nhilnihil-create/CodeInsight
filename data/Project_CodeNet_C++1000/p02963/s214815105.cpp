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

// 約数の列挙 O(√n)
vector<ll> divisor(ll n) {
    vector<ll> res;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            if (i != n / i) res.push_back(n / i);
        }
    }

    return res;
}

int main() {
    INIT;
    ll S;
    cin >> S;

    if (S == 1000000000000000000LL) {
        cout << 0 << " " << 0 << " " << 1000000000LL << " " << 0 << " " << 0
             << " " << 1000000000LL << endl;
        return 0;
    }

    ll x2 = 1000000000LL;
    ll y3 = S / 1000000000LL + 1LL;
    ll xy = y3 * 1000000000LL - S;
    vector<ll> divs = divisor(xy);
    // repv(divs) { cout << *it << " "; }
    // cout << endl;

    ll x3 = divs[SZ(divs) - 1];
    ll y2 = xy / x3;
    cout << 0 << " " << 0 << " " << x2 << " " << y2 << " " << x3 << " " << y3
         << endl;

    return 0;
}