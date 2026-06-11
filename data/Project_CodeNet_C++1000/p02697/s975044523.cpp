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

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, m;
   cin >> n >> m;
   if (n % 2) {
      for (int l = 2, r = n; l < r; l++, r--) {
         if ((m--) > 0) printf("%d %d\n", l, r);
      }
   } else {
      bool fg = false;
      for (int l = 2, r = n; l < r; l++, r--) {
         if (!fg && r - l <= n / 2) {
            l++;
            fg = true;
         }
         if ((m--) > 0) printf("%d %d\n", l, r);
      }
   }
   return 0;
}