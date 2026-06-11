#include <iostream>
#include <stdexcept>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;


int main() {
  const long long M = pow(10, 18);
  int N;
  cin >> N;
  vector <unsigned long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) { cout << 0 << endl; return 0; }
  }

  unsigned long long ans = 1;
  for (int i = 0; i < N; i++) {
    if (ans > M / A[i]) { cout << -1 << endl; return 0; }
    ans *= A[i];
  }
  cout << ans << endl;
  return 0;
}
