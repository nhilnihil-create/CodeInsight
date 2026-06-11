/*input
100 0
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, n;
  cin >> x >> n;
  vector<int> a(105);
  rep(i, n) {
    int p;
    cin >> p;
    a[p] = 1;
  }
  int l = x, r = x;
  int ans = x;
  while (1) {
    if (a[l] == 0) {
      ans = l;
      break;
    }
    else if (a[r] == 0) {
      ans = r;
      break;
    }
    if (l >= 1) l--;
    if (r <= 100) r++;
  }
  cout << ans << endl;
}