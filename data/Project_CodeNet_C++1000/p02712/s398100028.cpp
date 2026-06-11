#include <stdio.h>

using namespace std;
typedef unsigned long long llong;

#define MAX 100001
const llong mod = 1000000000 + 7;

int main()
{
  llong N;
  llong ans = 0;
  scanf("%llu", &N);
  for (llong i = 1; i <= N; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
      continue;
    ans += i;
  }
  printf("%llu\n", ans);

  return 0;
}