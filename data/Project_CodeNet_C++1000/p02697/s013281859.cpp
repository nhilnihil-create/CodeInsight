#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int L = N / 2;
  int R = L + 1;
  int min_L = N;
  vector<pair<int, int>> P;
  for (int d = 1; d < (N + 1) / 2; d += 2) {
    if (P.size() < M) {
      P.push_back({L + 1, R + 1});
    }
    min_L = min(min_L, L);
    L--;
    R++;
  }

  vector<int> D;
  for (int d = 2; d < (N + 1) / 2; d += 2) {
    D.push_back(N - d);
  }
  sort(D.begin(), D.end());

  L = min_L - 1;
  for (int d : D) {
    if (P.size() < M) {
      P.push_back({L + 1, L + d + 1});
    }
    L--;
  }

  sort(P.begin(), P.end());
  int offset = P[0].first - 1;
  for (auto& p : P) {
    p.first -= offset;
    p.second -= offset;
  }

  for (auto& p : P) {
    cout << p.first << " " << p.second << endl;
  }

  return 0;
}
