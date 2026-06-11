#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<vector<int>> A(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> A[i][j];
  
  int M;
  cin >> M;
  for (int i = 0; i < M; ++i) {
    int a;
    cin >> a;
    for (int j = 0; j < 3; ++j) for (int k = 0; k < 3; ++k) if (A[j][k] == a) A[j][k] = -1;
  }
  bool res = false;
  
  for (int i = 0; i < 3; ++i) {
    if (A[i][0] == -1 && A[i][1] == -1 && A[i][2] == -1) res = true;
   	if (A[0][i] == -1 && A[1][i] == -1 && A[2][i] == -1) res = true;
  }
  if (A[0][0] == -1 && A[1][1] == -1 && A[2][2] == -1) res = true;
  if (A[0][2] == -1 && A[1][1] == -1 && A[2][0] == -1) res = true;
  
  if (res) cout << "Yes" << endl;
  else cout << "No" << endl;
}
  
  
  