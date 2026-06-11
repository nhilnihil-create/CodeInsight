#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = -1;
  for (int i = 1; i <= 10000; i++) {
    if (a == (int)(i * 0.08) && b == (int)(i * 0.10)) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
  return 0;
}