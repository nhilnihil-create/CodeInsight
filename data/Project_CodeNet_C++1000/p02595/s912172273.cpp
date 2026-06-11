/*input
12 3
1 1
1 1
1 1
1 1
1 2
1 3
2 1
2 2
2 3
3 1
3 2
3 3
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  ll d;
  cin >> n >> d;
  int ans = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (x*x+y*y <= d*d) ans++;
  }
  cout << ans << endl;
}