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
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll n;
    cin >> n;
    vector<P> vec(n);
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        vec[i] = {a, b};
    }
    sort(vec.begin(), vec.end());

    ll ans = 1;
    ll cnt_max = 0;
    for (ll i = 0; i < n - 1; i++) {
        for (ll j = i + 1; j < n; j++) {
            P tei_v = {vec[j].fi - vec[i].fi, vec[j].se - vec[i].se};
            ll cnt = 0;
            for (ll k = 0; k < n - 1; k++) {
                for (ll l = k + 1; l < n; l++) {
                    if (tei_v == make_pair(vec[l].fi - vec[k].fi,
                                           vec[l].se - vec[k].se)) {
                        cnt++;
                    }
                }
            }
            chmax(cnt_max, cnt);
        }
    }

    cout << n - cnt_max << endl;
    return 0;
}