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

   int n, p;
   cin >> n >> p;
   string s;
   cin >> s;

   if (10 % p == 0) {
      ll ans = 0;
      rep(r, 0, n) {
         if ((s[r] - '0') % p == 0) {
            ans += r + 1;
         }
      }
      cout << ans << endl;
      return 0;
   }
   vector<int> d(n + 1);
   int ten = 1;
   rrep(i, n - 1, 0) {
      int a = (s[i] - '0') * ten % p;
      d[i] = (d[i + 1] + a) % p;
      ten *= 10;
      ten %= p;
   }
   vector<int> cnt(p);
   ll ans = 0;
   rrep(i, n, 0) {
      ans += cnt[d[i]];
      cnt[d[i]]++;
   }
   cout << ans << endl;
   return 0;
}