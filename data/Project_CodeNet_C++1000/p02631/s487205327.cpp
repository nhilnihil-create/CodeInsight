#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int x = 0;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    x ^= A[i];
  }
  for (const auto& a : A) {
    cout << (x ^ a) << (a == A.back() ? '\n' : ' ');
  }
  return 0;
}
