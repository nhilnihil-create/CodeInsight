/*input
3 3
1
3
1
3
1
3
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> cnt(n, 1);
  rep(i, k) {
    int d;
    cin >> d;
    rep(j, d) {
      int a;
      cin >> a, --a;
      cnt[a] = 0;
    }
  }
  int ans = 0;
  rep(i, n) ans += cnt[i];
  cout << ans << endl;
  return 0;
}