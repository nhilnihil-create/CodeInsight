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

ll dp[100005];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, m;
   cin >> n >> m;
   vector<int> broken(n + 1, false);
   rep(i, 0, m) {
      int a;
      cin >> a;
      broken[a] = true;
   }
   dp[n] = 1;
   rrep(i, n - 1, 0) {
      if (broken[i]) continue;
      dp[i] = (dp[i + 1] + dp[i + 2]) % MOD;
   }
   cout << dp[0] << endl;
   return 0;
}