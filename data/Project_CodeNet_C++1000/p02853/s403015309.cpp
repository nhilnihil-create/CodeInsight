#include <bits/stdc++.h>
using namespace std;
int main()
  {int X, Y; cin >> X >> Y;
  cout << 100000 * ((X * Y == 1) * 4 + max(0, 4 - X) + max(0, 4 - Y)) << endl;}