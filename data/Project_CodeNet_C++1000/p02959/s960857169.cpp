#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> A(N + 1), B(N);
  for (auto &a : A) cin >> a;
  for (auto &b : B) cin >> b;
  long long ans{};
  for (int i = 0; i != N; ++i) {
    auto d = min(B[i], A[i] + A[i + 1]);
    ans += d;
    A[i + 1] -= max(d - A[i], 0);
  }
  cout << ans << endl;
}