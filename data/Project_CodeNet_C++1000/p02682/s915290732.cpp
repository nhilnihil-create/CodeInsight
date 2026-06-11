/*input
2000000000 0 0 2000000000
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int ans = 0;
  if (k <= a) ans = k;
  else if (k <= a+b) ans = a;
  else ans = a-(k-a-b);
  cout << ans << endl;
  return 0;
}