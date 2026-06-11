#include <bits/stdc++.h>
using namespace std;

bool solve(int A, int B, int C, int K) {
  if (A < B && B < C) return true;
  if (K == 0) return false;
  return solve(2 * A, B, C, K - 1) || solve(A, 2 * B, C, K - 1) ||
         solve(A, B, 2 * C, K - 1);
}
int main(void) {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  cout << (solve(A, B, C, K) ? "Yes" : "No") << endl;
  return 0;
}