#include <stdio.h>

int main(void)
{
  int h, a;
  scanf("%d %d", &h, &a);
  int num = h / a + 1;
  printf("%d\n", num - ((h % a) == 0));
  return 0;
}
