#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;
template <class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
const long long INF = 1LL << 60;

int main() {
    ll N;
    cin >> N;
    vector<pair<ll, ll>> XL(N);
    rep(i, N) {
        ll x, l;
        cin >> x >> l;
        XL[i].first = x + l;
        XL[i].second = x - l;
    }
    sort(XL.begin(), XL.end());
    ll max = -INF;
    ll ans = 0;
    rep(i, N) {
        if (max <= XL[i].second) {
            max = XL[i].first;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
