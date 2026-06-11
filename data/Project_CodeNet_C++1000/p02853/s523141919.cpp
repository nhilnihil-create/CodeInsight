#include <bits/stdc++.h>
using namespace std;
int main()
  {int ps[] = {3, 2, 1, 0};
  int X, Y; cin >> X >> Y;
  cout << 100000 * ((X * Y == 1) * 4 + ps[min(4, X) - 1] + ps[min(4, Y) - 1]) << endl;}