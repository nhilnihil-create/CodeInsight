#include <iostream>
#include <cstdio>

using namespace std;

long long f(int n)
{
  if (n == 0) return 1;
  return f(n - 1) * n;
}
int main()
{
  int n;
  scanf("%d", &n);
  printf("%lld\n", f(n));
  return 0;
}