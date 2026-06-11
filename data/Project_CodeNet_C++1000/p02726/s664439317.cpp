#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, X, Y; cin >> N >> X >> Y;
  vector<int> cs(N); for (int i{1}; i < N; ++i) for (int j{i + 1}; j <= N; ++j) ++cs[min({j - i, abs(X - i) + 1 + abs(Y - j), abs(Y - i) + 1 + abs(X - j)})];
  for (int k{1}; k < N; ++k) cout << cs[k] << "\n";}