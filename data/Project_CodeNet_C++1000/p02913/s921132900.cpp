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

int dp[5005][5005];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   string s;
   cin >> n >> s;
   rrep(i, n - 1, 0) {
      rrep(j, n - 1, 0) {
         if (s[i] != s[j])
            dp[i][j] = 0;
         else
            dp[i][j] = dp[i + 1][j + 1] + 1;
      }
   }
   int ans = 0;
   rep(i, 0, n) rep(j, 0, n) {
      if (i >= j) continue;
      int now = min(dp[i][j], j - i);
      ans = max(ans, now);
   }
   cout << ans << endl;
   return 0;
}