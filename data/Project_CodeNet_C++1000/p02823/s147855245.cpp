#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, a, b;

  cin >> n >> a >> b;

  if (a % 2 == b % 2) {
    cout << (b - a) / 2;
  } else {
    cout << min(a - 1, n - b) + 1 + ((b - a) / 2);
  }

  return 0;
}