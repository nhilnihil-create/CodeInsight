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
    ll N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    if (P == 2 || P == 5) {
        ll ans = 0;
        for (int i = N - 1; i >= 0; --i) {
            if ((S[i] - '0') % P == 0) {
                ans += i + 1;
            }
        }
        cout << ans << endl;
        return 0;
    }

    map<ll, ll> mp;
    ++mp[0];
    ll cur = 0;
    ll fac = 1;
    for (int i = N - 1; i >= 0; --i) {
        cur = (cur + (S[i] - '0') * fac) % P;
        fac *= 10;
        fac %= P;
        ++mp[cur];
    }

    ll ans = 0;
    for (auto e : mp) {
        ans += e.second * (e.second - 1) / 2;
    }

    cout << ans << endl;
}