#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int A[N+1], B[N+1], C[N];
  
  A[0] = -1;
  B[0] = -1;
  C[0] = -1;
  
  for (int i = 0; i < N; i++) cin >> A[i+1];
  for (int i = 0; i < N; i++) cin >> B[i+1];
  for (int i = 0; i < N-1; i++) cin >> C[i+1];

  
  int ans = 0;
  
  for (int i = 1; i <= N; i++) {
    ans += B[A[i]];
    if (A[i] - A[i-1] == 1) ans += C[A[i-1]];
  }
  cout << ans << endl;
  
}

