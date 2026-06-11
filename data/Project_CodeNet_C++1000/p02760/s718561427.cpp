#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  rep(i, 3) rep(j, 3) cin >> A[i][j];

  int N;
  cin >> N;

  int b = 0;
  rep(i, N) {
    cin >> b;
    rep(i, 3) {
      rep(j, 3) {
        if (A[i][j] == b) A[i][j] = 0;
        if (
            // 横
            (A[0][0] == 0 && A[0][1] == 0 && A[0][2] == 0) ||
            (A[1][0] == 0 && A[1][1] == 0 && A[1][2] == 0) ||
            (A[2][0] == 0 && A[2][1] == 0 && A[2][2] == 0) ||
            // 縦
            (A[0][0] == 0 && A[1][0] == 0 && A[2][0] == 0) ||
            (A[0][1] == 0 && A[1][1] == 0 && A[2][1] == 0) ||
            (A[0][2] == 0 && A[1][2] == 0 && A[2][2] == 0) ||
            // 斜め
            (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0) ||
            (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0)) {
          cout << "Yes" << endl;
          return 0;
        }
      }
    }
  }

  cout << "No" << endl;
  return 0;
}