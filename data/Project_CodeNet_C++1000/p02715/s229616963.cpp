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

inline ll modpow(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n > 0)
    {
        if (n & 1)
        {
            ret *= a;
            ret %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<ll> cnt(K + 1);
    ll ans = 0;
    for (int i = K; i >= 1; --i) {
        ll tmp = modpow(K/ i, N, mod);

        for (int l = i * 2; l <= K; l += i) {
            tmp -= cnt[l];
        }

        while (tmp < 0) tmp += mod;

        ans += (tmp * i) % mod;
        ans %= mod;
        cnt[i] = tmp;
    }

    cout << ans << endl;
}