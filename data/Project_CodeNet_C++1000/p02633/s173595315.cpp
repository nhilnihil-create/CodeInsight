#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int X;
  cin >> X;
  cout << X * 360 / __gcd(360, X) / X << endl;
  return 0;
}