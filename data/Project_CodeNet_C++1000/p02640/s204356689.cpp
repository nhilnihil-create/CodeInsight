/*input
2 100
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x, y;
  cin >> x >> y;
  int z = 4*x-y;
  bool ok = true;
  if (z%2 != 0) ok = false;
  if (z < 0 ||  2*x < z) ok = false;
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
}