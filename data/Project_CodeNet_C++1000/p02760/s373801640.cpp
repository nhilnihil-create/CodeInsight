#include <bits/stdc++.h>
#define debug(x) cerr << #x << ": " << x << endl
#define debugArray(x, n)                           \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
  cerr << #x << "[" << hoge << "]: " << x[hoge] << endl
using namespace std;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A[3][3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> A[i][j];
    }
  }
  int N;
  cin >> N;
  while (N--) {
    int b;
    cin >> b;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (A[i][j] == b) {
          A[i][j] = -1;
        }
      }
    }
  }
  bool isbingo = false;
  for (int i = 0; i < 3; i++) {
    int sum = 0;
    for (int j = 0; j < 3; j++) {
      sum += A[i][j];
    }
    isbingo |= sum == -3;
  }
  for (int j = 0; j < 3; j++) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
      sum += A[i][j];
    }
    isbingo |= sum == -3;
  }
  isbingo |= A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1;
  isbingo |= A[2][0] == -1 && A[1][1] == -1 && A[0][2] == -1;
  cout << (isbingo ? "Yes" : "No") << endl;
  return 0;
}