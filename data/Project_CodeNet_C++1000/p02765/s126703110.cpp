#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX 10
const llong mod = 1000000000 + 7;

int main()
{
  int N, R;
  scanf("%d%d", &N, &R);
  if (N >= 10)
  {
    printf("%d\n", R);
  }
  else
  {
    printf("%d\n", R + 100 * (10 - N));
  }

  return 0;
}