#include <bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  }else {
    return (gcd(b,(a%b)));
  }
}
signed main() {
  int n;
  cin >> n;
  cout <<  360 / gcd(n, 360) << "\n";
  return 0;
}
