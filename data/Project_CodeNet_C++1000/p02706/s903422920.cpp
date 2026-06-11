#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  int A;
  int S = 0;
  for (int i = 0; i < M; i++) {
    cin >> A;
    S += A;
  }
  if (N - S < 0)
    cout << -1 << endl;
  else if (N - S >= 0)
    cout << N-S << endl;
}