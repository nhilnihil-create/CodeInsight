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
   vector<int> a(n + 1), b(n);
   rep(i, 0, n + 1) cin >> a[i];
   rep(i, 0, n) cin >> b[i];

   ll ans = 0;
   rep(i, 0, n) {
      int com = min(a[i], b[i]);
      ans += com;
      a[i] -= com;
      b[i] -= com;
      com = min(a[i + 1], b[i]);
      ans += com;
      a[i + 1] -= com;
      b[i] -= com;
   }
   cout << ans << endl;
   return 0;
}