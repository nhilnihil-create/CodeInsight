#include <bits/stdc++.h>
 using namespace std;
 typedef long long ll;
 #define rep(i, j, n) for(int i = j; i < (int)(n); i++)
 ll MOD = 1000000007;
 ll pow_mod(ll x, ll n) {
   x %= MOD;
   if (n == 0) return 1;
   else if (n % 2 == 1) return (x * pow_mod(x, n - 1)) % MOD;
   else return pow_mod((x * x) % MOD, n / 2) % MOD;
 }
 ll comb(ll l, ll m) {
   if (l < m) return 0;
   ll t1 = 1, t2 = 1;
   for (ll i = l; i >= l - m + 1; i--) t1 = t1 * i % MOD;
   for (ll i = 1; i <= m; i++) t2 = t2 * i % MOD;
   t2 = pow_mod(t2, MOD - 2);
   return t1 * t2 % MOD;
 }

 int main() {
   ll N, K;
   cin >> N >> K;
   for (ll i = 1; i < K + 1; i++) cout << comb(K - 1, i - 1) * comb(N - K + 1, i) % MOD << endl;
 }
