#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  for (int i{1}; i <= 9; ++i) for (int j{1}; j <= 9; ++j) if (i * j == N) puts("Yes"), exit(0);
  puts("No");}