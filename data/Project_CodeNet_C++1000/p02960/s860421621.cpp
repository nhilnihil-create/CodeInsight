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

ll dp[100005][13];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   string s;
   cin >> s;
   int n = s.size();

   dp[0][0] = 1;
   rep(i, 0, n) {
      if (s[i] == '?') {
         rep(d, 0, 10) rep(j, 0, 13) {
            (dp[i + 1][(j * 10 + d) % 13] += dp[i][j]) %= MOD;
         }
      } else {
         int d = s[i] - '0';
         rep(j, 0, 13) { (dp[i + 1][(j * 10 + d) % 13] += dp[i][j]) %= MOD; }
      }
   }

   ll ans = dp[n][5];
   cout << ans << endl;
   return 0;
}