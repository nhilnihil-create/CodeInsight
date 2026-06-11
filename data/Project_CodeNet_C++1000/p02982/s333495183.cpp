#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<long long>> x(N, vector<long long>(D));
  for (int i = 0; i < N; ++i) for (int j = 0; j < D; ++j) cin >> x[i][j];
  
  long long res = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i+1; j < N; ++j) {
      long long dis = 0;
      for (int d = 0; d < D; ++d) dis += (x[i][d] - x[j][d]) * (x[i][d] - x[j][d]);
      long long s = (long long)(sqrt(dis) + 0.1);
      if (s*s == dis) ++res;
    }
  }
  cout << res << endl;
}