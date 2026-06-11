#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int prz(int a) {
  if (a == 3)
    return 100000;
  else if (a == 2)
    return 200000;
  else if (a == 1)
    return 300000;
  return 0;
}

int main() {
  int X, Y;
  cin >> X >> Y;

  int ans = 0;
  ans += prz(X);
  ans += prz(Y);

  if (X == 1 & Y == 1) ans += 400000;

  cout << ans << endl;
  return 0;
}