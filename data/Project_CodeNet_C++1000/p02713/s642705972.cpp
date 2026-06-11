#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

inline ll GCD(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return GCD(b, a % b);
}

int main() {
    ll K;
    cin >> K;
    ll ans = 0;
    for (int i = 1; i <= K; ++i) {
        for (int j = 1; j <= K; ++j) {
            ll tmp = GCD(i, j);
            if (tmp == 1) {
                ans += K;
            } else {
                for (int l = 1; l <= K; ++l) {
                    ans += GCD(tmp, l);
                }
            }
        }
    }
    cout << ans << endl;
}