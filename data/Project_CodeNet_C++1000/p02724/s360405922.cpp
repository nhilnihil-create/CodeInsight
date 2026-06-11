#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;
  int r500 = x / 500 * 2;
  int r5 = x % 500 / 5;
  cout << r500*500 + r5*5 << endl;
  return 0;
}
