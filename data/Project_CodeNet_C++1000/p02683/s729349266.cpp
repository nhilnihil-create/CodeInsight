#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, X;
  cin >> N >> M >> X;
  vector<int> C(N);
  vector<vector<int>> A(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    cin >> C.at(i);
    for (int j = 0; j < M; j++) {
      cin >> A.at(i).at(j);
    }
  }
  int ans = 100000000;
  bool ok = false;
  for (int tmp = 0; tmp < (1 << N); tmp++) {
    bitset<12> s(tmp);
    int memo = 0;
    vector<int> S(M);
    for (int i = 0; i < N; i++) {
      if (s.test(i)) {
        memo += C.at(i);
        for (int j = 0; j < M; j++) {
          S.at(j) += A.at(i).at(j);
        }
      }
    }
    for (int i = 0; i < M; i++) {
      if (S.at(i) < X) {
        break;
      }
      if (i == M - 1) {
        ok = true;
        ans = min(ans, memo);
      }
    }
  }
  if (ok) {
    cout << ans << endl;
  }
  else {
    cout << -1 << endl;
  }
}