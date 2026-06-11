#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N), R(N);
  for (int i = 0; i != N; ++i) {
    cin >> A[i];
    R[0] += A[i];
  }

  for (int i = 1; i < N; i += 2) R[0] -= 2 * A[i];
  cout << R[0];
  for (int i = 1; i != N; ++i) {
    R[i] = 2 * A[i - 1] - R[i - 1];
    cout << " " << R[i];
  }
  cout << endl;
}
