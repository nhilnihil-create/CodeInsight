#include <bits/stdc++.h>
using namespace std;

int main () {
  long long N, M, K, a, b, ans = 0;
  cin >> N >> M >> K;
  vector<long long> A(N+1,0), B(M+1,0);
  for (long long i = 0; i < N; i++) {
    cin >> a;
    A[i+1] = A[i] + a;
  }
  for (long long i = 0; i < M; i++) {
    cin >> b;
    B[i+1] = B[i] + b;
  }
  long long j;
  for (long long i = 0; i <= N; i++) {
    if (A[i] > K) break;
    j = upper_bound(B.begin(), B.end(), K-A[i]) - B.begin() - 1;
    j = max(0LL,min(j,M));
    ans = max(ans, i+j);
    
  }
  cout << ans << endl;
}
    
