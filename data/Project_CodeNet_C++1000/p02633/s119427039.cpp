#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int y = x;
  int k = 1;
  while (y != 0) {
    y += x;
    y %= 360;
    k++;
  }

  cout << k << endl;
  return 0;
}