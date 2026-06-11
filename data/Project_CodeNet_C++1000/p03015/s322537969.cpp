#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

int dp[100005][2];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   string s;
   cin >> s;
   dp[0][0] = 1;
   int n = s.size();
   rep(i, 0, n) {
      /* a_i + b_i = 0 */
      if (s[i] == '0') {
         dp[i + 1][0] = dp[i][0];
         dp[i + 1][1] = dp[i][1];
      } else {
         dp[i + 1][1] = (dp[i][0] + dp[i][1]) % MOD;
      }
      /* a_i + b_i = 1 */
      if (s[i] == '0') {
         (dp[i + 1][1] += 2 * dp[i][1] % MOD) %= MOD;
      } else {
         (dp[i + 1][0] += 2 * dp[i][0] % MOD) %= MOD;
         (dp[i + 1][1] += dp[i][1] * 2 % MOD) %= MOD;
      }
   }
   int ans = (dp[n][0] + dp[n][1]) % MOD;
   cout << ans << endl;
   return 0;
}