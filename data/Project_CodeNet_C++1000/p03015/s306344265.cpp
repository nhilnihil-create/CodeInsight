#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
  char L[100001];
  long long pow2[100001], pow3[100001];
  
  scanf("%s", L);
  int n = strlen(L);
  
  pow3[0] = 1;
  pow2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow3[i] = (3 * pow3[i - 1]) % 1000000007;
    pow2[i] = (2 * pow2[i - 1]) % 1000000007;
  }
  
  int cnt = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (L[i] == '1') {
      long long tmp = (pow2[cnt] * pow3[n - i - 1]) % 1000000007;
      ans = (ans + tmp) % 1000000007;
      cnt++;
    }
  }
  ans = (ans + pow2[cnt]) % 1000000007;
  
  printf("%lld\n", ans);
  
  return 0;
}