#include <bits/stdc++.h>
using namespace std;

typedef unsigned long  long ull;
typedef unsigned int ui;

int main() {
  ull N, M, K;
  cin >> N >> M >> K;
  vector<ull> a(N);
  vector<ull> b(M);
  vector<ull> A(N+1);
  vector<ull> B(M+1);
  A[0] = 0;
  B[0] = 0;
  for(ull i = 0; i < N; i++) {
    cin >> a[i];
    A[i+1] = a[i] + A[i];
  }
  for(ull i = 0; i < M; i++) {
    cin >> b[i];
    B[i+1] = b[i] + B[i];
  }

  ull ans = 0;
  ull j = M;
  for(ull i = 0; i <= N; i++) {
    if(A[i] > K) break;
    while(B[j] > K - A[i]) {
      j--;
    }
    ans = max(ans, i + j);
  }
  cout << ans << endl;
  return 0;
}
