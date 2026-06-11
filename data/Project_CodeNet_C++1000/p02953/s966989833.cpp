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
   vector<int> a(n + 1);
   rep(i, 0, n) cin >> a[i];
   a[n] = INF;
   rep(i, 0, n) {
      if (i == 0 || a[i] > a[i - 1]) a[i]--;
      if (a[i] > a[i + 1]) {
         cout << "No" << endl;
         return 0;
      }
   }
   cout << "Yes" << endl;
   return 0;
}