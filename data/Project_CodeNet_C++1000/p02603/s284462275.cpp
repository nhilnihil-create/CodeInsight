#include <iostream>
#include <vector>
using namespace std;

int main() {
  long long N, s{}, ans{1000};
  cin >> N;
  vector<int> A(N);
  for (auto &a: A) cin >> a;
  for (int i = 0; i!= N; ++i) {
    if (i != N - 1 && A[i] < A[i+1]) {
      s += ans / A[i];
      ans -= ans / A[i] * A[i];
    } else if (i == N - 1 || A[i] > A[i+1]) {
      ans += s * A[i];
      s = 0;
    }
  }
  cout << ans << endl;
}
