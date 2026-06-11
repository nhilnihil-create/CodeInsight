#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

ll MOD = 1e9 + 7;
ll FAC_MAX = 2000;

ll mpow(ll a, ll n) {  // a^n (mod MOD)
    // 二分累乗法 O(log n)
    ll ans = 1;
    while (n != 0) {
        if (n & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return ans;
}

vi fac_vec;
ll fac(ll n) {  // n! (mod MOD)
    if (fac_vec.empty()) {
        fac_vec = vi(FAC_MAX + 10);  // (FAC_MAX+10)! まで対応
        fac_vec[0] = 1;
        for (ll i = 1; i < fac_vec.size(); i++) {
            fac_vec[i] = fac_vec[i - 1] * i % MOD;
        }
    }
    return fac_vec[n];
}

vi ifac_vec;
ll ifac(ll n) {  // (n!)^(-1) (mod MOD)
    // フェルマーの小定理より、k^(-1)≡k^(MOD-2) なので、
    // (n!)^(-1)≡(n!)^(MOD-2)
    if (ifac_vec.empty()) {
        ifac_vec = vi(FAC_MAX + 10);  // {(FAC_MAX+10)!}^(-1) まで対応
        ifac_vec[0] = 1;
        for (ll i = 1; i < ifac_vec.size(); i++) {
            ifac_vec[i] = ifac_vec[i - 1] * mpow(i, MOD - 2) % MOD;
        }
    }
    return ifac_vec[n];
}

ll comb(ll a, ll b) {  // aCb (mod MOD)
    // aCb = a! * (b!)^(-1) * {(a-b)!}^(-1)
    if (a < b || a < 0 || b < 0) return 0;
    return (ifac(b) * ifac(a - b) % MOD) * fac(a) % MOD;
}

int main() {
    ll N, K;
    cin >> N >> K;

    for (ll i = 1; i <= K; i++) {
        // 青を入れる場所 comb(N - K + 1, i)
        // 青の分け方 comb(K - 1, i-1)
        ll ans = comb(N - K + 1, i) * comb(K - 1, i - 1) % MOD;
        cout << ans << endl;
    }
}
