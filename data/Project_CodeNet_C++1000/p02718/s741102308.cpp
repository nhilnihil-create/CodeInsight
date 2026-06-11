#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long llong;

#define MAX 1001
const llong mod = 1000000000 + 7;

int main()
{
  int N, M;
  double border = 0;
  int A[MAX];
  int flag;

  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
    border += A[i];
  }
  border /= 4 * M;

  sort(A, A + N, greater<int>());

  flag = 1;
  for (int i = 0; i < M; i++)
  {
    if (A[i] < border)
      flag = 0;
  }

  if (flag)
    printf("Yes");
  else
    printf("No");

  return 0;
}