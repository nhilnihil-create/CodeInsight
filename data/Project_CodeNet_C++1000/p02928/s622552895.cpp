#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int main()
{
  int N, K;
  int A[2000];
  
  scanf("%d %d", &N, &K);
  
  for (int i = 0; i < N; i++) scanf("%d", A + i);
  
  long long ans = 0;
  int tmp = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
      if (A[j] > A[j + 1]) {
        swap(A[j], A[j + 1]);
        tmp++;
      }
    }
  }
  
  ans = (long long)tmp * K % MOD;
  
  int cnt = 0;
  long long coef = ((long long)K * (K - 1) / 2) % MOD;
  for (int i = 1; i < N; i++) {
    if (A[i] != A[i - 1]) cnt = i;
    ans = (ans + coef * cnt) % MOD;
  }
  
  printf("%lld\n", ans);
  
  return 0;
}