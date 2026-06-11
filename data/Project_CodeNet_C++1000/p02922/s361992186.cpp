#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int a, b;
  scanf("%d %d", &a, &b);

  int now = 1, ans = 0;
  while (now < b) {
    ++ans;
    now += (a - 1);
  }

  printf("%d\n", ans);

  return (0);
}