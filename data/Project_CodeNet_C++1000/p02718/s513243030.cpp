#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, M; cin >> N >> M;
  vector<int> A(N); for (auto &a : A) cin >> a; sort(A.rbegin(), A.rend());
  puts(4 * M * A[M - 1] >= accumulate(begin(A), end(A), 0) ? "Yes" : "No");}