#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;

ll mod_pow(ll a, ll x, ll mod) {
    if (x == 1)
        return a;
    if (x % 2 == 0) {
        ll tmp = mod_pow(a, x/2, mod);
        return tmp*tmp%mod;
    }
    else {
        return a*mod_pow(a, x-1, mod) % mod;
    }
}

int main() {
    int n, k;  cin >> n >> k;

    vector<ll> dp(k+1, 0);
    dp[k] = 1;
    ll ans = k;

    for (ll i = k; i > 1; i--) {
        dp[i-1] = mod_pow(k/(i-1), n, mod);
        for (ll j = 2; j * (i-1) <= k; j++) {
            dp[i-1] -= dp[j*(i-1)];
            dp[i-1] %= mod;
        }
        ans += (i-1)*dp[i-1]%mod;
        ans %= mod;
    }


    cout << (ans+mod)%mod << endl;

    return 0;
}