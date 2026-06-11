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
constexpr ll mod = 2019;

int main() {
    string S;
    cin >> S;

    ll N = S.size();

    map<ll, ll> mp;
    ll cur = 0;
    ll fac = 1;
    ++mp[cur];
    for (int i = 1; i <= N; ++i) {
        cur = (cur + (S[N - i] - '0') * fac) % mod;
        ++mp[cur];
        fac *= 10;
        fac %= mod;
    }

    ll ans = 0;
    for (auto &e : mp) {
        ans += e.second * (e.second - 1) / 2;
    }

    cout << ans << endl;
}