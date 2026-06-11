#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  int X;
  cin >> X;

  int ans = 360 / gcd(360, X);
  cout << ans << endl;
  return 0;
}