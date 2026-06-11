#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  auto s = 0.;
  for (int i = 0; i < N; ++i)
    {double A; cin >> A;
    s += 1. / A;}
  cout << setprecision(16) << 1. / s << endl;}