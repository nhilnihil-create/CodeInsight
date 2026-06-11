#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  long long K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> visited(N, -1);
  int a = 0;  // 最初の町からサイクルにたどり着くまでの移動回数
  int T = 0;  // サイクルの周期
  int p = 0;
  for (int i = 0; i <= N; i++) {
    if (visited[p] != -1) {
      T = i;
      break;
    }
    visited[p] = i;
    p = A[p];
  }
  a = visited[p];
  T -= a;
  p = 0;
  if (K <= a) {
    for (int i = 0; i < K; ++i) p = A[p];
  } else {
    for (int i = 0; i < a; ++i) p = A[p];
    K = (K - a) % T;
    for (int i = 0; i < K; ++i) p = A[p];
  }
  cout << p + 1 << endl;
  return 0;
}
