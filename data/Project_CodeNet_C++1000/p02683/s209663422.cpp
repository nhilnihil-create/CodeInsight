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
    ll N, M, X;
    cin >> N >> M >> X;
    vector<vector<ll>> books(N, vector<ll>(M + 1));
    rep(i, N) {
        rep(j, M + 1) { cin >> books[i][j]; }
    }

    ll ans = INF;
    int mask = 1;

    for (int i = pow(2, N); i > 0; --i) {
        int cnt = i;
        vector<ll> table(M + 1, 0);
        for (int j = 0; j < N; ++j) {
            if ((cnt & mask) == 0) {
                cnt = cnt >> 1;
                continue;
            }
            cnt = cnt >> 1;
            for (int k = 0; k < M + 1; ++k) {
                table[k] += books[j][k];
            }
        }

        bool is_ok = true;
        for (int l = 1; l < M + 1; ++l) {
            if (table[l] < X) {
                is_ok = false;
                break;
            }
        }
        if (is_ok) {
            chmin(ans, table[0]);
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}