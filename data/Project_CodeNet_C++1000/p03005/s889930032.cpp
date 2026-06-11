#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int N, K;

  scanf("%d%d", &N, &K);
  if (N == K || K == 1) {
    printf("0\n");
    return 0;
  }
  N -= K;
  printf("%d\n", N);

  return 0;
}
