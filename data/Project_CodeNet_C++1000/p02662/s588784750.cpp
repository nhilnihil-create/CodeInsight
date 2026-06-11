//1hour 10minutes
#include <bits/stdc++.h>
#define dbg(x) cout << #x << ": " << (x) << '\n'
#define ff first
#define ss second
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
const ll mod = 998244353;

int main() {
   ios::sync_with_stdio(false);   cin.tie(NULL);   cout.tie(NULL);

   int n, s;
   cin >> n >> s;
   vector <ll> a(n);
   for (auto &i : a)
      cin >> i;
   vector <vector <ll>> dp(n + 1, vector <ll> (s + 1));
   vector <ll> bin(n + 1, 1);
   for (int i = 1; i <= n; i++) {
      bin[i] = (2 * bin[i - 1]);
   }

   dp[0][0] = 1;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j <= s; j++) {
         dp[i + 1][j] += (2 * dp[i][j]) % mod;
         dp[i + 1][j] %= mod;
         if (dp[i][j] && j + a[i] <= s) {
            dp[i + 1][j + a[i]] += dp[i][j];
            dp[i + 1][j + a[i]] %= mod;
         }
      }
   }

   cout << dp[n][s] % mod << '\n';

   return 0;
}