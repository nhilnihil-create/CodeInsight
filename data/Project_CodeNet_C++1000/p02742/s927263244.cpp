#include <bits/stdc++.h>
using namespace std;

int main() {
  long long w, h;
  cin >> h >> w;
  long long ans = 0;
  if (h == 1 || w == 1) {
    ans = 1;
  }
  else {
    ans = h * w;
    ans = (ans + 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
