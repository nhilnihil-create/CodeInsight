#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, s{}; cin >> N;
  int D[N]; for (int &d : D) cin >> d;
  for (int i{}; i < N; ++i) for (int j{i + 1}; j < N; ++j) s += D[i] * D[j];
  cout << s;}