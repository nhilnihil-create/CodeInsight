#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)

int main() {
   ll n, k;
   cin >> n >> k;
   vector<ll> v(n);
   for (int i = 0; i < n; i++) cin >> v[i];
 
   ll ans = 0;
   for (int i = 0; i < n; i++) {
     ll migi = 0, zentai = 0;
     for (int j = i; j < n; j++)
       if (v[i] > v[j]) migi++;
     for (int j = 0; j < n; j++)
       if (v[i] > v[j]) zentai++;
 
     ans += migi * k % MOD;
     ans %= MOD;
     ans += (k - 1) * k / 2 % MOD * zentai % MOD;
     ans %= MOD;
   }
   cout << ans << endl;
 }