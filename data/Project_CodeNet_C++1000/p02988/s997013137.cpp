#include <bits/stdc++.h>
using namespace std;
int main()
  {int n, c{}; cin >> n;
  int P[n]; for (int &p : P) cin >> p;
  for (int i{1}; i < n - 1; ++i) c += P[i] == P[i - 1] + P[i] + P[i + 1] - min({P[i - 1], P[i], P[i + 1]}) - max({P[i - 1], P[i], P[i + 1]});
  cout << c;}