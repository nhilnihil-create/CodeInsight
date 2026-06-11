#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> x;
  if (x >= 10000)
    cout << "1";
  else {
    n = x / 100;
    if (x <= 105 * n)
      cout << "1";
    else
      cout << "0";
  }
  return 0;
}