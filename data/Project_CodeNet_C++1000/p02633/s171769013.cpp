#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  cout << (360 / gcd(n, 360)) << '\n';
  return 0;
}