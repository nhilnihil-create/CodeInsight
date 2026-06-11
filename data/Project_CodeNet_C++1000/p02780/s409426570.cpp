#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, s{}, m{}; cin >> N >> K;
  vector<int> ps(N); for (auto &p : ps) cin >> p;
  for (int i = 0; i < N; ++i)
    {s += ps[i]; if (i >= K) s -= ps[i - K];
    m = max(m, s);}
  cout << fixed << setprecision(12) << (m + K) / 2. << endl;}