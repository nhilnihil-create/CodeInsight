#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N), cnt(N + 1);

    ll ans = 1;

    ll ins = 3;
    rep(i, N) {
        cin >> A[i];
        cnt[A[i]]++;

        if (A[i] == 0) {
            ans *= ins;
            ans %= mod;
            ins--;
            continue;
        } else {
            ans *= cnt[A[i] - 1];
            ans %= mod;
            cnt[A[i] - 1]--;
        }
    }

    cout << ans << "\n";

    return 0;
}