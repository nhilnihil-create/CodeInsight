#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

llong comb(int n)
{
  return (llong)n * (n - 1) / 2;
}

int main()
{
  int N;
  scanf("%d", &N);
  int A[MAX];
  int cnt[MAX];
  llong total = 0;
  for (int i = 0; i < N; i++)
  {
    cnt[i + 1] = 0;
  }

  for (int i = 0; i < N; i++)
  {
    scanf("%d", &A[i]);
    cnt[A[i]]++;
  }

  for (int i = 1; i <= N; i++)
  {
    int j = cnt[i];
    total += comb(j);
  }

  for (int i = 0; i < N; i++)
  {
    int j = cnt[A[i]];
    printf("%lld\n", total - comb(j) + comb(j - 1));
  }

  return 0;
}