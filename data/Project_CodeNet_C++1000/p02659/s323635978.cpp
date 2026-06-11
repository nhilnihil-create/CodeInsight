/*input
1 0.01
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll a, b = 0;
  cin >> a;
  rep(i, 4) {
    char c;
    cin >> c;
    if (i == 1) continue;
    b = b*10+(c-'0');
  }
  ll ans = a*b/100;
  cout << ans << endl;
}