#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, a, c{}; cin >> N;
  for (int i{1}; i <= N; ++i) cin >> a, c += i % 2 * (a % 2);
  cout << c;}