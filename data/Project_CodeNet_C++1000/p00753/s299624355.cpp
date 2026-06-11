#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main() {
  int n, t, M = 123457*2;
  vector<bool> E(M, true);
  vector<int> A(M, 0);
  t = sqrt(M) + 1;
  E[0] = false; E[1] = false;
  for (int i = 2; i < t; ++i) {
    if (E[i]) {
      for (int j = i; j*i < M; ++j) E[i*j] = false;
    }
  }
  for (int i = 2; i < M; ++i) {
    if (E[i]) A[i] = A[i-1] + 1;
    else A[i] = A[i-1];
  }
  while (cin >> n, n) {
    cout << A[2*n] - A[n] << endl;
  }
}