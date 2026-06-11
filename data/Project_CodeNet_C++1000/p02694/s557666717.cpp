/*input
1333333333
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;
  ll m = 100;
  for (int i = 1; i < 1001001001; ++i) {
    m = m+(m/100);
    if (m >= x) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}