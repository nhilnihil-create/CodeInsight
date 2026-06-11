#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 200001

int main()
{
  int N, ans = 0;
  llong A[MAX];

  scanf("%d", &N);

  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &A[i]);
  }

  sort(A, A + N);
  int Amax = A[N - 1];
  int chk[Amax + 1];
  for (int i = 0; i <= Amax; i++)
  {
    chk[i] = 0;
  }
  // エスとラテネスの篩
  for (int i = 0; i < N; i++)
  {

    // for (int j = i + 1; j < N; j++)
    // {
    //   if (A[j] % A[i] == 0)
    //     B[j] = false;
    // }
    if (chk[A[i]] == 0)
    {
      for (int j = 2; j * A[i] <= Amax; j++)
      {
        chk[j * A[i]]++;
      }
    }
    if (i > 0 && A[i] == A[i - 1])
      chk[A[i]]++;
  }

  for (int i = 0; i < N; i++)
  {
    if (chk[A[i]] == 0)
      ans++;
  }
  printf("%d\n", ans);

  return 0;
}