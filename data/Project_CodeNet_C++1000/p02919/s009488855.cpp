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
   vector<int> a(n);
   rep(i, 0, n) cin >> a[i];
   rep(i, 0, n) a[i]--;
   vector<int> id(n);
   rep(i, 0, n) id[a[i]] = i;

   set<int> s;
   ll ans = 0;
   rrep(x, n - 1, 0) {
      int i = id[x];
      ll c = 0;

      s.insert(i);
      vector<int> l(2, -1), r(2, n);
      auto it = s.find(i);
      rep(j, 0, 2) {
         if (it == s.begin()) break;
         it--;
         l[j] = *it;
      }
      it = s.find(i);
      rep(j, 0, 2) {
         it++;
         if (it == s.end()) break;
         r[j] = *it;
      }
      vector<int> ls(2);
      ls[0] = i - l[0];
      ls[1] = l[0] - l[1];
      vector<int> rs(2);
      rs[0] = r[0] - i;
      rs[1] = r[1] - r[0];
      c = ls[0] * rs[1] + (ll)ls[1] * rs[0];
      ans += c * (x + 1);
   }
   cout << ans << endl;
   return 0;
}