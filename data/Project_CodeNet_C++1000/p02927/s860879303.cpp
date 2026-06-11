#include <cstdio>

int main()
{
  int m, d;
  scanf("%d%d", &m, &d);
  int ans = 0;
  for (int i = 1; i <= m; ++i)
  {
    for (int j = 22; j <= d; ++j)
    {
      if (j % 10 < 2) continue;
      if (i == (j / 10) * (j % 10)) ++ans;
    }
  }
  printf("%d\n", ans);
  return 0;
}