#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  double V[N], r; for (auto &v: V) cin >> v; sort(V, V + N); r = V[0];
  for (int i{1}; i < N; ++i) r = (r + V[i]) / 2;
  printf("%.9f", r);}