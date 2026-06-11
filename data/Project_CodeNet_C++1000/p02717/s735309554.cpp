#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int tmp;
  int X, Y, Z;
  scanf("%d", &X);
  scanf("%d", &Y);
  scanf("%d", &Z);

  tmp = X;
  X = Y;
  Y = tmp;

  tmp = X;
  X = Z;
  Z = tmp;

  printf("%d %d %d\n", X, Y, Z);

  return 0;
}