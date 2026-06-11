#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  for (int X{}; X <= N; ++X) if (108 * X / 100 == N) cout << X, exit(0);
  puts(":(");}