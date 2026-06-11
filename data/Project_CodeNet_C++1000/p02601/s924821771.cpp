#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  
  while (a >= b) {
    b *= 2;
    k--;
  }
  while (b >= c) {
    c *= 2;
    k--;
  }
  
  if (k >= 0) cout << "Yes\n";
  else cout << "No\n";
}