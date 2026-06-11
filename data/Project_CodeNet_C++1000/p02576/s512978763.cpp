#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x, t;
  cin >> n >> x >> t;
  
  int ans = (n % x != 0) ? (n / x + 1) * t : n / x * t;
  
  cout << ans << endl;
}