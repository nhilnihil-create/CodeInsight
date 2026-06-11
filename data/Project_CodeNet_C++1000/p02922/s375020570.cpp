#include <bits/stdc++.h>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  for (int k = 0;;++k) {
    if (a * k - (k - 1) >= b) {
      cout << k;
      return 0;
    }
  }
  return 0;
}
