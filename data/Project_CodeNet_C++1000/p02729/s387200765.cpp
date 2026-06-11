#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> V;
  for (int i = 0; i < N; i++) {
    V.push_back(0);
  }
  for (int i = 0; i < M; i++) {
    V.push_back(1);
  }
  int ans = 0;
  for (int i = 0; i < N + M; i++) {
    for (int j = 0; j < i; j++) {
      if ((V.at(i) + V.at(j)) % 2 == 0) ans++;
    }
  }
  cout << ans << "\n";
}