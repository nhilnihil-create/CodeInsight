#include <bits/stdc++.h>
using namespace std;
int main()
  {int K, N, m; cin >> K >> N;
  vector<int> A(N); for (auto &a : A) cin >> a;
  m = K - (A.back() - A[0]); for (int i{1}; i < N; ++i) m = max(m, A[i] - A[i - 1]);
  cout << K - m << endl;}