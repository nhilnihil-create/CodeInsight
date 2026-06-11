#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int N;
  int flag = 0;
  scanf("%d", &N);
  for (int i = 0; i < 3; i++)
  {
    if (N % 10 == 7)
      flag = 1;
    N /= 10;
  }
  if (flag)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}