#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 1000000001
const llong mod = 1000000000 + 7;

int main()
{
  llong X;
  scanf("%lld", &X);
  int min = -120, max = 120;
  int a = 0, b = 0;
  for (llong i = min; i < max; i++)
  {
    int flag = 0;
    for (llong j = min; j < i; j++)
    {
      if (i * i * i * i * i - j * j * j * j * j == X)
      {
        flag = 1;
        a = i;
        b = j;
        break;
      }
    }
    if (flag)
    {
      break;
    }
  }
  printf("%d %d", a, b);

  return 0;
}