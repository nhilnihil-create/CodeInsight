#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 10001
const llong mod = 1000000000 + 7;

int main()
{
  int N, M;
  int A;

  scanf("%d%d", &N, &M);
  for (int i = 0; i < M; i++)
  {
    scanf("%d", &A);
    N -= A;
  }

  if (N >= 0)
    printf("%d\n", N);
  if (N < 0)
    printf("-1");

  return 0;
}