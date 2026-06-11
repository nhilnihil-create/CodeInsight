#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

const ll M = 200001;
ll facto[M], inv[M], factoinv[M];

int modpow(ll a, ll n) {
  if (n == 0) return 1;
  if (n == 1) return a % mod;
  if (n % 2 == 1) return (a * modpow(a, n - 1)) % mod;
  ll t = modpow(a, n / 2);
  return (t * t) % mod;
}

void nCrmod() {
    facto[0] = facto[1] = 1; inv[1] = 1, factoinv[0] = factoinv[1] = 1;
    
    for (int i = 2; i < M; i++) {
        facto[i] = i * facto[i - 1] % mod;
        inv[i] = mod - inv[mod % i] * (mod / i) % mod;
        factoinv[i] = inv[i] * factoinv[i - 1] % mod;
    }
}

int main() {
    ll n, a, b; cin >> n >> a >> b;
    nCrmod();
    const ll Max = max(a, b) + 1;
    ll niko[Max];
    niko[0] = 1;
    niko[1] = n;
    for (int i = 2; i < Max; i++) {
        niko[i] = ((n - i + 1) * niko[i - 1]) % mod;
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