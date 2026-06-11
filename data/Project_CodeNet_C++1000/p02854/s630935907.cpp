#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <vector>
#include <iomanip>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  int A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  long S = 0;
  for (int i = 0; i < N; i++) {
    S += A[i];
  }
  long m;
  m = S;
  long Sr = 0;
  for (int i = 0; i < N - 1; i++) {
    Sr += A[i];
    if (abs(S - Sr * 2) < m) {
      m = abs(S - Sr * 2);
    }
  }
  cout << m << endl;
  return 0;
}
