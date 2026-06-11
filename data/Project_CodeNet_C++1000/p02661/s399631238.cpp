#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int> A(N), B(N); for (int i = 0; i < N; ++i) cin >> A[i] >> B[i]; sort(begin(A), end(A)); sort(begin(B), end(B));
  auto m = (N - 1) / 2; cout << (N % 2 ? B[m] - A[m] + 1 : B[m] + B[m + 1] - (A[m] + A[m + 1]) + 1) << endl;}