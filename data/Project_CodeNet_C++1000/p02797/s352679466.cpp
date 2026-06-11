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
    ll n, k, s;
    cin >> n >> k >> s;
    vector<ll> ans(n, 1000000000);
    if (s == 1000000000) {
        rep(i, n) ans[i] = 999999999;
    }

    rep(i, k) ans[i] = s;
    rep(i, n) {
        cout << ans[i];
        if (i == n - 1)
            cout << "\n";
        else
            cout << " ";
    }
    return 0;
}