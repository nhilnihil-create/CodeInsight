#include <bits/stdc++.h>
using namespace std;
int main()
  {uint64_t X, p{1}; cin >> X;
  do {p *= 360 / X; X = 360 % X;}
  while (X);
  cout << p << endl;}