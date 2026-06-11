#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;

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