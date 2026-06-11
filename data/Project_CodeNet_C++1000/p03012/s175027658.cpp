#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, m(1e7), s, t; cin >> N;
  int W[N]; for (int &w: W) cin >> w;
  for (int T{}; T < N; ++T)
    {s = t = 0; for (int i{}; i < N; ++i) if (i <= T) s += W[i]; else t += W[i];
    m = min(m, abs(s - t));}
  cout << m;}