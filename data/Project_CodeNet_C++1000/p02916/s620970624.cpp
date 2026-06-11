#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, s = 0; cin >> N;
  vector<int> A(N, 0), C(N, 0);
  for(int i = 0; i < N; i++) cin >> A[i];
  for(int i = 0; i < N; i++) {
    int B; cin >> B; s += B;
  }
  for(int i = 0; i < N; i++) cin >> C[i];
  for(int i = 0; i < N - 1; i++) {
    if(A[i] == A[i + 1] - 1) s += C[A[i] - 1];
  }
  cout << s << endl;
  return 0;
}