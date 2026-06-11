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

   int n, k;
   cin >> n >> k;
   int mx = (n - 1) * (n - 2) / 2;
   if (mx < k) {
      puts("-1");
      return 0;
   }
   vector<P> ans;
   rep(i, 0, n - 1) { ans.push_back(P(i + 1, n)); }
   int add = mx - k;
   vector<P> edge;
   rep(i, 0, n - 1) rep(j, 0, i) edge.push_back(P(i + 1, j + 1));
   rep(i, 0, add) ans.push_back(edge[i]);
   cout << ans.size() << endl;
   rep(i, 0, ans.size()) {
      cout << ans[i].first << " " << ans[i].second << endl;
   }
   return 0;
}