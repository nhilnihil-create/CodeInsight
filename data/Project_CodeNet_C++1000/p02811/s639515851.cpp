#include <stdio.h>

int main()
{
  int K;
  int X;
  scanf("%d", &K);
  scanf("%d", &X);
  (K * 500 >= X) ? puts("Yes") : puts("No");
  return 0;
}