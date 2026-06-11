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

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n;
   cin >> n;
   vector<vector<P>> to(n);
   rep(i, 0, n) {
      int a;
      cin >> a;
      rep(j, 0, a) {
         int x, y;
         cin >> x >> y;
         x--;
         to[i].emplace_back(x, y);
      }
   }
   int ans = 0;
   rep(s, 0, 1 << n) {
      bool ok = true;
      rep(i, 0, n) {
         if (s >> i & 1) {
            rep(j, 0, to[i].size()) {
               if (((s >> to[i][j].first) & 1) != to[i][j].second) {
                  ok = false;
               }  
            }
         }
      }
      if (ok) chmax(ans, __builtin_popcount(s));
   }
   cout << ans << endl;
   return 0;
}