#include <bits/stdc++.h>
using namespace std;

int v[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{
  int k;
  scanf("%d", &k);
  k--;
  printf("%d\n", v[k]);
  return 0;
}