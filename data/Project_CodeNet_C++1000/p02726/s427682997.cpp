#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 2001
const llong mod = 1000000000 + 7;

int N, X, Y;

int main()
{
  int A[MAX];
  for (int i = 0; i < MAX; i++)
  {
    A[i] = 0;
  }

  scanf("%d%d%d", &N, &X, &Y);

  for (int i = 1; i < N; i++)
  {
    int distance;
    for (int j = i + 1; j <= N; j++)
    {
      int xi = abs(X - i);
      int yj = abs(Y - j);
      distance = min(j - i, xi + yj + 1);
      A[distance]++;
    }
  }

  for (int i = 1; i < N; i++)
  {
    printf("%d\n", A[i]);
  }

  return 0;
}