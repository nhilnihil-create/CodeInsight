#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int ca = min(a, k);
  int cc = max(0, k - a - b);
  int result = ca - cc;
  cout << result << endl;
  return 0;
}