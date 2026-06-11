#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int A, B, C, D;
  scanf("%d%d", &A, &B);
  scanf("%d%d", &C, &D);

  int flag = 1;
  while (A > 0 && C > 0)
  {
    if (flag)
    {
      C -= B;
      flag = 0;
    }
    else
    {
      A -= D;
      flag = 1;
    }
  }

  if (flag)
  {
    printf("No");
  }
  else
  {
    printf("Yes");
  }

  return 0;
}