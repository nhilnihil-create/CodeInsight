#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, m(1e7); cin >> N;
  int X[N]; for (int &x: X) cin >> x;
  for (int P{}; P <= 100; ++P)
    {int s{}; for (int x: X) s += (x - P) * (x - P);
    m = min(m, s);}
  cout << m;}