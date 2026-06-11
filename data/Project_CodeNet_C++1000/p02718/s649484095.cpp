#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int sum = accumulate(A.begin(), A.end(), 0);
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if ((long double) A.at(i) < (long double) sum / (4 * M)) continue;
    cnt++;
  }
  cout << ((cnt >= M) ? "Yes" : "No") << "\n";
}