/*input
1
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x;
  cin >> x;
  for (ll a = -1000; a <= 1000; ++a) {
    for (ll b = -1000; b <= 1000; ++b) {
      ll a5 = a*a*a*a*a;
      ll b5 = b*b*b*b*b;
      if (a5-b5 == x) {
        cout << a << " " << b << endl;
        return 0;
      }
    }
  }
  return 0;
}