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
    ll N;
    cin >> N;
    vector<pll> A(N);

    for (ll i = 0; i < N; ++i) {
        ll num;
        cin >> num;
        A[i] = make_pair(num, i);
    }

    sort(all(A), greater<pll>());

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1, 0));
    for (ll i = 0; i < N; ++i) {
        for (ll j = 0; j <= i; ++j) {
            chmax(dp[i + 1][j + 1],
                  dp[i][j] + A[i].first * abs(A[i].second - j));
            chmax(dp[i + 1][j],
                  dp[i][j] + A[i].first * abs(A[i].second - (N - 1 - (i - j))));
        }
    }

    ll ans = 0;
    for (auto e : dp[N]) {
        chmax(ans, e);
    }

    cout << ans << endl;
}