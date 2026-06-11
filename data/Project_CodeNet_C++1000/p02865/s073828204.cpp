#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, ans{}; cin >> N;
  for (int a{1}; a < N; ++a) ans += a < N - a;
  cout << ans;}