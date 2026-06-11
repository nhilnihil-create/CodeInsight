#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

ll modPow(ll n, ll p, ll mod) {
    n %= mod;
    // return (n^p) % mod
    if (p == 0)
        return 1;
    ll res = modPow(n * n % mod, p / 2, mod);
    if (p % 2 == 1)
        res = res * n % mod;
    return res;
}

int main() {
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    ll mod = 1e9 + 7;
    vector<ll> cnt(K + 1, 0);
    for (ll g = K; g >= 2; g--) {
        ll ng = K / g;
        cnt[g] = modPow(ng, N, mod);
        for (int k = 2; k * g <= K; k++) {
            cnt[g] -= cnt[k * g];
            while (cnt[g] < 0) {
                cnt[g] += mod;
            }
        }
        ans = (ans + cnt[g] * g) % mod;
    }

    cnt[1] = modPow(K, N, mod);
    for (int i = 2; i <= K; i++) {
        cnt[1] -= cnt[i];
        while (cnt[1] < 0) {
            cnt[1] += mod;
        }
    }
    ans = (ans + cnt[1]) % mod;
    cout << ans % mod << endl;
}
