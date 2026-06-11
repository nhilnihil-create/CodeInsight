#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N;
  cin >> M;
  vector<int> A(M);
  int sum = 0;
  for (int i=0; i<M; i++) {
    cin >> A[i];
    sum += A[i];
  }
  if (N < sum) {
    cout << -1 << endl;
  } else {
    cout << N - sum << endl;
  }
}

