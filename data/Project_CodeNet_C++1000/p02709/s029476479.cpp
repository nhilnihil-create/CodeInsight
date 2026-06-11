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
// const int MOD = 998244353;

ll dp[2005][2005];
int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];
   vector<P> p;
   rep(i, 0, n) p.emplace_back(a[i], i);
   sort(p.rbegin(), p.rend());
   rep(i, 0, n) {
      int pi = p[i].second;
      rep(l, 0, i + 1) {
         int r = i - l;
         chmax(dp[i + 1][l + 1], dp[i][l] + ll(pi - l) * a[pi]);
         chmax(dp[i + 1][l], dp[i][l] + ll((n - r - 1) - pi) * a[pi]);
      }
   }
   ll ans = 0;
   rep(i, 0, n + 1) chmax(ans, dp[n][i]);
   cout << ans << endl;
   return 0;
}