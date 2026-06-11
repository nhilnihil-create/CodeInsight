#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long int;

int main() {
  ll N, K;
  cin >> N >> K;

  vector<vector<int>> next(60, vector<int>(N));
  for (int v = 0; v < N; ++v) cin >> next[0][v], --next[0][v];
  for (int d = 0; d + 1 < 60; ++d) {
    for (int v = 0; v < N; ++v) {
      next[d + 1][v] = next[d][next[d][v]];
    }
  }
  int v = 0;
  for (int d = 0; d < 60; ++d) {
    if (K & (1LL << d)) v = next[d][v];
  }
  cout << v + 1 << endl;
}