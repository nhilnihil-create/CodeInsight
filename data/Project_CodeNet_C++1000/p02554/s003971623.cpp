#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

const ll mod = 1000000007;

ll powmod(ll x, ll y) {
    ll res = 1;
    for (ll i = 0; i < y; i++) {
        res = res * x % mod;
    }
    return res;
}

int main() {
    ll N;
    cin >> N;

    ll ans = powmod(10, N) - powmod(9, N) - powmod(9, N) + powmod(8, N);
    ans %= mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
}
