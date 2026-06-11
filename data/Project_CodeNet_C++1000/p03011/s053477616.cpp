#include <bits/stdc++.h>
using namespace std;

int main() {
  int p, q, r, ans;
  cin >> p >> q >> r;
  ans = min(p+q,min(q+r,r+p));
  cout << ans << endl;
  return 0;
}
