#include <bits/stdc++.h>
#define ll long long
#define rep(i, n)(for i-0;i<(n);++i)
using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
const double PI = 3.14159265358979323846;
int main() {
  int n, r;
  cin >> n >> r;
  if (n >= 10) {
    cout << r;
  } else {
    cout << r + (100 * (10 - n));
  }
}