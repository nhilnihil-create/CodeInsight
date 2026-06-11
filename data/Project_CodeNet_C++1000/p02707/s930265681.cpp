#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

int main()
{
  int N;
  int A[MAX];
  int a;
  int current = 0;
  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    A[i + 1] = 0;
  }

  for (int i = 0; i < N - 1; i++)
  {
    scanf("%d", &a);
    A[a]++;
  }

  for (int i = 0; i < N; i++)
  {
    printf("%d\n", A[i + 1]);
  }

  return 0;
}