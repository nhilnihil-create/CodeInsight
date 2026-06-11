#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int A, B, C, K;
  int ans = 0;
  scanf("%d%d%d%d", &A, &B, &C, &K);

  if (A > K)
  {
    ans += 1 * K;
    printf("%d\n", ans);
    return 0;
  }
  else
  {
    ans += 1 * A;
  }
  K -= A;

  if (B > K)
  {
    ans += 0 * K;
    printf("%d\n", ans);
    return 0;
  }
  else
  {
    ans += 0 * B;
  }
  K -= B;

  if (C > K)
  {
    ans += -1 * K;
    printf("%d\n", ans);
    return 0;
  }
  else
  {
    ans += -1 * C;
  }

  printf("%d\n", ans);

  return 0;
}