/**
 *    author:  morato
 *    created: 25.08.2020 20:00:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int f = 0;
  if (a == b) {
    f = (c != a);
  } else {
    if (b == c) {
      f = (c != a);
    } else {
      if (a == c) {
        f = (c != b);
      }
    }
  }
  cout << (f ? "Yes\n" : "No\n");
  return 0;
}