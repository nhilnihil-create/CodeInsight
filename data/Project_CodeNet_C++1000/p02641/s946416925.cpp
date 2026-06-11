#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b) {
    if (a < b) a = b;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) a = b;
    return true;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

int main() {
    ll X, N;
    cin >> X >> N;
    vector<bool> p(1000, false);
    rep(i, N) {
        ll num;
        cin >> num;
        p[num] = true;
    }

    ll ans;
    ll upper;
    ll lower;
    for (int i = X + 1;; ++i) {
        if (p[i] == false) {
            upper = i;
            break;
        }
    }
    for (int i = X;; --i) {
        if (p[i] == false) {
            lower = i;
            break;
        }
    }

    if (X - lower <= upper - X) {
        ans = lower;
    } else {
        ans = upper;
    }

    cout << ans << endl;
}