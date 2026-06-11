#include <stdio.h>
#include <algorithm>

using namespace std;
typedef unsigned long long llong;

#define MAX 4000
const llong mod = 1000000000 + 7;

int main()
{
  int N;
  char S[MAX];
  llong Rlen = 0, Glen = 0, Blen = 0;
  llong ans = 0;

  scanf("%d", &N);
  scanf("%s", S);

  for (int i = 0; i < N; i++)
  {
    switch (S[i])
    {
    case 'R':
      Rlen++;
      break;
    case 'G':
      Glen++;
      break;
    case 'B':
      Blen++;
      break;
    }
  }
  ans = Rlen * Glen * Blen;

  for (int i = 0; i < N; i++)
  {
    for (int j = i; j < N; j++)
    {
      int k = j + j - i;
      if (k < N && S[i] != S[j] && S[j] != S[k] && S[k] != S[i])
        ans--;
    }
  }

  printf("%llu\n", ans);

  return 0;
}