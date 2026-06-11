#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = 1000000007;

ll pow (ll a, ll n) {
    ll res = 1;
    ll count = a;
    while (n) {
        if (n & 1) res = res * count % MOD;
        n /= 2;
        count = count * count % MOD;
    }
    return res;
}

int main() {
    ll n, k; cin >> n >> k;
    vector<ll> sub(k+1,0);
    sub[k] = 1;
    for (ll i = k-1; i >= 1; i--) {
        ll num = k / i;
        sub[i] = pow(num, n);
        for (ll j = i * 2; j <= k; j += i) {
            sub[i] -= sub[j];
            if (sub[i] < 0) sub[i] += MOD;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++) { ans += i * sub[i]; ans %= MOD; }
    cout << ans << endl;
    return 0;
}