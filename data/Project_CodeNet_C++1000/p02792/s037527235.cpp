#include <iostream>
using namespace std;
int f(int n) {
  auto s = to_string(n);
  return s[0] * 10 + s.back() - '0' * 11;
}
int N, d[100];
int main() {
  cin >> N;
  while (N) ++d[f(N--)];
  for (int i = 1; i < 100; ++i) N += d[i] * d[i % 10 * 10 + i / 10];
  cout << N << endl;
}
