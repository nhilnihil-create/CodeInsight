#include <stdio.h>
#include <functional>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 51
#define MAX2 61
const llong mod = 1000000000 + 7;

int N, M, Q;
int x, X[MAX];
int A[MAX], B[MAX], C[MAX], D[MAX];
llong ans = 0;

void func()
{
  llong result = 0;
  for (int i = 0; i < Q; i++)
  {
    if (X[B[i] - 1] - X[A[i] - 1] != C[i])
    {
      continue;
    }
    result += D[i];
  }
  ans = max(ans, result);
}

void comb(int n, int m)
{
  // 要素数が少ない場合
  if (n < N + M - 1)
  {
    // |が少ない場合
    if (m < M - 1)
    {
      comb(n + 1, m + 1);
    }
    // oが少ないとき
    if (n - m < N)
    {
      X[n - m] = m + 1;
      comb(n + 1, m);
    }
    return;
  }

  func();
}

int main()
{

  scanf("%d%d%d", &N, &M, &Q);

  int Ans[11];
  for (int i = 0; i < N; i++)
  {
    Ans[i] = 1;
  }

  for (int i = 0; i < Q; i++)
  {
    scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
  }

  comb(0, 0);

  printf("%lld\n", ans);

  return 0;
}