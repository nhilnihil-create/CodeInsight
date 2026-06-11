#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long ans = 0;
  int N;
  
  scanf("%d", &N);
  ans = (long long)(N - 1) * N * (N + 1) / 6 + (long long)N * (N + 1) / 2;
  
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    if (u > v) swap(u, v);
    ans -= (long long)u * (N - v + 1);
  }
  
  printf("%lld\n", ans);
  
  return 0;
}