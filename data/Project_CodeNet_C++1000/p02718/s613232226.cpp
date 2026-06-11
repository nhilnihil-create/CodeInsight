#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int sum = accumulate(A.begin(), A.end(), 0L);
  double tmp = sum / (4.0 * M);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (A.at(i) >= tmp) cnt++;
  }
  cout << ((cnt >= M) ? "Yes" : "No") << "\n";
}