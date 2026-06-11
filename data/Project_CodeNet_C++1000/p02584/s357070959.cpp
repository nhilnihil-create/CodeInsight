#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t x, k, d, n;
  cin >> x >> k >> d;
  x = abs(x);
  n = k - x/d;
  if(n <= 0) {
    x -= d*k;
  }
  else {
    x %= d;
    if(n%2==1)
      x = d-x;
  }
  cout << x << endl;
}