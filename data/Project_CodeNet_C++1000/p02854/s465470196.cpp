#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i)
    cin >> A[i];
  for (int i = 1; i < N; ++i)
    A[i] += A[i - 1];
  long long ans = 1000000000000000001;
  for (int i = 0; i < N - 1; ++i)
    ans = min(abs(A[i] - (A[N - 1] - A[i])), ans);
  cout << ans << endl;
}
