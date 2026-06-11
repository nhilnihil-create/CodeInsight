#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;

ll mod_pow(ll x, ll n) {
    if (n == 0) return 1;
    ll res = mod_pow(x * x % mod, n / 2);
    if (n & 1) res = res * x % mod;
    return res;
}

ll com(ll a, ll b) {
    if (a < b) return 0;
    ll res = 1;
    for (ll i = 0; i < b; i++) {
        res *= (a - i);
        res %= mod;
        res *= mod_pow(b - i, mod - 2);
        res %= mod;
    }
    return res;
}

int main() {
    int n,a,b; cin >> n >> a >> b;
    ll ans = mod_pow(2, n) - 1;
    ans %= mod;
    ans -= com(n,a);
    ans -= com(n,b);
    ans += 2 * mod;
    ans %= mod;
    cout << ans << "\n";
}