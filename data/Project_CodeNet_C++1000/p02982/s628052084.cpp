#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;
  vector<vector<int>> A(N, vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) cin >> A[i][j];
  }
  int cnt = 0;
  for (int i; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int total = 0;
      for (int k = 0; k < D; k++) {
        int tmp = pow(A[i][k] - A[j][k], 2);
        total += tmp;
      }
      if(ceil(sqrt(total)) == floor(sqrt(total))) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}