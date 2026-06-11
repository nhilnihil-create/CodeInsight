#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 100
const llong mod = 1000000000 + 7;

int main()
{
  int S, W;
  scanf("%d%d", &S, &W);

  if (W >= S)
  {
    printf("unsafe\n");
  }
  else
  {
    printf("safe\n");
  }

  return 0;
}