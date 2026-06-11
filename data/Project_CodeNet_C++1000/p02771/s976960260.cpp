#include <bits/stdc++.h>
#define ll long long
#define rep(i, n)(for i-0;i<(n);++i)
using namespace std;
int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }
const double PI = 3.14159265358979323846;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a == b && a != c) {
    cout << "Yes";
  } else if (c == b && a != c) {
    cout << "Yes";
  } else if (a == c && b != c) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}