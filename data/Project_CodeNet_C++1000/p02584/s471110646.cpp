#include <bits/stdc++.h>
using namespace std;

int main() {
  long x, k, d;
  cin >> x >> k >> d;
  x = abs(x);
  long c = x / d;
  long dist = x - d * min(c, k);
  if (k < c || (k - c) % 2 == 0) {
    cout << abs(dist) << endl;
  } else {
    cout << abs(dist - d) << endl;
  }
}
