#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

ll modpow(ll a, ll n) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  if (n % 2 == 1) return (a * modpow(a, n - 1)) % mod;
  ll t = modpow(a, n / 2);
  return (t * t) % mod;
}

int main() {
    ll n, a, b; cin >> n >> a >> b;
    const ll Max = 200001;
    ll niko[Max], inv[Max];
    niko[0] = 1;
    niko[1] = n;
    inv[1] = 1;
    for (int i = 2; i < Max; i++) {
        niko[i] = ((n - i + 1) * niko[i - 1]) % mod;
        inv[i] = modpow(i, mod - 2);
        niko[i] = niko[i] * inv[i] % mod;
        
    }
    ll ans = modpow(2, n);
    ans--;
    if (ans < 0) ans += mod;
    ans -= niko[a];
    if (ans < 0) ans += mod;
    ans -= niko[b];
    if (ans < 0) ans += mod;
    cout << ans << endl;
    return 0;
}