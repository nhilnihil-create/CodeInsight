#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  vector<int>A(N + 1);
  vector<int>B(N + 1);
  vector<int>C(N + 1);
  for (int i = 1; i <= N; i ++) cin >> A[i];
  for (int i = 1; i <= N; i ++) cin >> B[i];
  for (int i = 1; i < N; i ++) cin >> C[i];
  int ans = 0;
  int pre = -1;
  for (int i = 1; i <= N; i ++) {
    ans += B[A[i]];
    if (pre == A[i] - 1) ans += C[A[i] - 1];
    pre = A[i];
  }
  cout << ans << endl;
}
