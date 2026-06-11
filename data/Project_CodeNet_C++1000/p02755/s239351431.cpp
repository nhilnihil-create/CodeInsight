#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int toA(int n)
{
  return n * 8 / 100;
}
int toB(int n)
{
  return n / 10;
}

int main()
{
  int A, B;
  int ans = -1;
  scanf("%d%d", &A, &B);

  for (int i = 1; i <= 1000; i++)
  {
    if (A == toA(i) && B == toB(i))
    {
      ans = i;
      break;
    }
  }

  printf("%d\n", ans);

  return 0;
}