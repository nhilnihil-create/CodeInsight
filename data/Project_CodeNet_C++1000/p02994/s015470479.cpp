#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, L, m(1e9), s{}; cin >> N >> L;
  for (int i{}, x; i < N; ++i) m = abs(x = L + i) < abs(m) ? x : m, s += x;
  cout << s - m;}