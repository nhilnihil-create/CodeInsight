#include <stdio.h>
#include <stdexcept>
#include <iostream>

using namespace std;
typedef unsigned long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  llong base = 100, X;
  int ans = 0;
  scanf("%llu", &X);

  while (base < X)
  {
    base += base / 100;
    ans++;
  }

  printf("%d\n", ans);

  return 0;
}