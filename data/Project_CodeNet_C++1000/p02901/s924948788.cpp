#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> B(M), C(M);
  for (int i = 0; i < M; i++) {
    cin >> C.at(i);
    int b;
    cin >> b;
    while (b--) {
      int c;
      cin >> c;
      B.at(i) += 1 << (c - 1);
    }
  }
  vector<long> DP(1 << N, 1e18);
  DP.at(0) = 0;
  for (int bit = 0; bit < 1 << N; bit++) {
    for (int i = 0; i < M; i++) {
      DP.at(bit | B.at(i)) = min(DP.at(bit | B.at(i)), DP.at(bit) + C.at(i));
    }
  }
  long ans = DP.at((1 << N) - 1);
  cout << ((ans == 1e18) ? -1 : ans) << "\n";
}