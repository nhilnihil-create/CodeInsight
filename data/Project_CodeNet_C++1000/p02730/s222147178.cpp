#include <cstdio>
#include <cstring>

using namespace std;
typedef long long llong;

#define MAX 100
const llong mod = 1000000000 + 7;

int main()
{
  char S[MAX];
  int N;
  int isA = 1, isB = 1, isC = 1;
  scanf("%s", S);

  N = strlen(S);
  for (int i = 0; i < N / 2; i++)
  {
    if (S[i] != S[N - 1 - i])
      isA = 0;
  }

  int L = (N - 1) / 2;
  for (int i = 0; i < L / 2; i++)
  {
    if (S[i] != S[L - 1 - i])
      isB = 0;
  }

  int m = (N + 3) / 2;
  int M = N - m;
  for (int i = 0; i < M / 2; i++)
  {
    if (S[m - 1 + i] != S[N - 1 - i])
      isC = 0;
  }

  if (isA && isB && isC)
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}