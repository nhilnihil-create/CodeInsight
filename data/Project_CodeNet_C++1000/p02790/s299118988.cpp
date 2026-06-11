#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, x;
  string y, ans = "";
  cin >> a >> b;
  
  if (a <= b) {
    x = b;
    y = to_string(a);
  } else {
    x = a;
    y = to_string(b);
  }
  
  for (int i = 0; i < x; i++) ans += y;

  cout << ans << endl;;
}