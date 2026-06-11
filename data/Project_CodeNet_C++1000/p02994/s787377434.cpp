#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, L; cin >> N >> L;
  cout << (N - 1) * L + N * (N - 1) / 2 - min(max(0, -L), N - 1);}