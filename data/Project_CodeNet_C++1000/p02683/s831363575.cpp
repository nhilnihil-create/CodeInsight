#include <stdio.h>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 13
const llong mod = 1000000000 + 7;
const int sumOver = 1e5 * 13;

int main()
{
  int N, M, X;
  int A[MAX][MAX], C[MAX], Y[MAX];

  scanf("%d%d%d", &N, &M, &X);

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &C[i]);
    for (int j = 0; j < M; j++)
    {
      scanf("%d", &A[i][j]);
    }
  }

  // bitを利用
  // 2のN+1乗
  int size = 1;
  for (int i = 0; i < N; i++)
  {
    size *= 2;
  }
  int ans = sumOver;
  for (int i = 0; i < size; i++)
  {
    int cSum = 0, flag = 1;
    for (int i = 0; i < M; i++)
    {
      Y[i] = 0;
    }
    for (int j = 0; j < N; j++)
    {
      // bitが立ってたら
      if ((i >> j) % 2)
      {
        cSum += C[j];
        for (int k = 0; k < M; k++)
        {
          Y[k] += A[j][k];
        }
      }
    }
    for (int j = 0; j < M; j++)
    {
      if (Y[j] < X)
      {
        flag = 0;
        break;
      }
    }

    if (flag)
    {
      ans = min(cSum, ans);
    }
  }
  if (ans == sumOver)
  {
    printf("-1\n");
    return 0;
  }

  printf("%d", ans);

  return 0;
}