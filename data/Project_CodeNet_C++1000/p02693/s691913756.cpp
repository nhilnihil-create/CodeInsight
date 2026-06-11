#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 1001
const llong mod = 1000000000 + 7;

int main()
{
  int K, A, B;
  scanf("%d", &K);
  scanf("%d%d", &A, &B);

  for (int i = A; i < B + 1; i++)
  {
    if (i % K == 0)
    {
      printf("OK\n");
      return 0;
    }
  }

  printf("NG\n");

  return 0;
}