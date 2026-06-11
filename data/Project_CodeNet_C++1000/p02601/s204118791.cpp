#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  while (k--) {
    if (a >= b) b *= 2;
    else if (b >= c) c *= 2;
  }
  cout << ((a < b && b < c) ? "Yes" : "No") << endl;
  return 0;
}