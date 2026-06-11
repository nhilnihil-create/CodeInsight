#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, H, p{}, c{}, m{}; cin >> N;
  while (cin >> H) (p >= H ? m = max(m, ++c) : c = 0), p = H;
  cout << m;}