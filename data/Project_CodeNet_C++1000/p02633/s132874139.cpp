#include <bits/stdc++.h>
using namespace std;
int main()
  {int X, k{1}; cin >> X;
  while (k * X % 360) ++k;
  cout << k << endl;}