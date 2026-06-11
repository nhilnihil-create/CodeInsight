#include <cstdio>

void rec(int i, int j)
{
  if (j == 10) return;

  printf("%dx%d=%d\n", i, j, i * j);
  rec(i, j + 1);
}

signed main(void)
{
  for (int x = 1; x < 10; x++) rec(x, 1);
}