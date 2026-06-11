#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;

  int ans = 0;
  while (b <= a) {
    b *= 2;
    ans++;
  }
  while (c <= b) {
    c *= 2;
    ans++;
  }

  cout << (ans <= k ? "Yes" : "No") << '\n';
  return 0;
}
