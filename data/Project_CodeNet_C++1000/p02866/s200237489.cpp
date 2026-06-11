#include <bits/stdc++.h>

using namespace std;
const int MOD = 998244353;

long long mod_pow(long long a, long long n)
{
  long long ret = 1;
  while (n) {
    if (n % 2) {
      ret = (ret * a) % MOD;
    }
    a = (a * a) % MOD;
    n /= 2;
  }
  return ret;
}

int main()
{
  int N;
  int d[100000], cnt[100000];
  
  scanf("%d", &N);
  fill(cnt, cnt + N, 0);
  
  int ma = 0;
  for (int i = 0; i < N; i++) {
    scanf("%d", d + i);
    cnt[d[i]]++;
    ma = max(ma, d[i]);
  }
  
  if (d[0] != 0 || cnt[0] != 1) {
    printf("0\n");
    return 0;
  }
  
  long long ans = 1;
  for (int i = 1; i <= ma; i++) {
    ans = ans * mod_pow(cnt[i - 1], cnt[i]) % MOD;
  }
  
  printf("%lld\n", ans);
  
  return 0;
}