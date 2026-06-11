#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &e : A) cin >> e;
  sort(A.begin(), A.end());
  vector<bool> B(A[N-1]+1,true);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (!B[A[i]]) continue;
    if (A[i] == A[i+1]) B[A[i]] = false;
    if (B[A[i]]) ans++;
    for (int j = 2; A[i]*j <= A[N-1]; j++) B[j*A[i]] = false;
  }
  cout << ans << endl;
}