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

int main() {
    ll N, M;
    cin >> N >> M;
    ll cnt = 0;
    for (ll i = 1; i <= M / 2; ++i) {
        if (cnt == M) {
            break;
        }
        cout << i << " " << M + 1 - i << endl;
        ++cnt;
    }

    for (ll i = 1; i <= M / 2 + 1; ++i) {
        if (cnt == M) {
            break;
        }
        cout << M + i << " " << 2 * M + 2 - i << endl;
        ++cnt;
    }
}