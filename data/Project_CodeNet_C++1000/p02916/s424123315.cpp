#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n - 1);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < n; i++) cin >> B[i];
  for(int i = 0; i < n-1; i++) cin >> C[i];
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += B[A[i] - 1];
    if (i == n - 1) break;
    if (A[i] + 1 == A[i + 1]) cnt += C[A[i]-1];
  }
  cout << cnt << endl;
  return 0;
}
