#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 10;
const int mod = 1e9 + 7;
ll qpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0), cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 1;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    // ans = ((ans * (n)) % mod * (n - 1)) % mod;
    // ans = ans * qpow(10, n - 2) % mod;
    ans = (((qpow(10, n) - qpow(9, n) + mod) % mod - qpow(9, n) + mod) % mod + qpow(8, n)) % mod;
    cout << ans % mod << endl;
    return 0;
}
