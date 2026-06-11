#include <cstdio>
#include <vector>
#include <string>

using namespace std;
typedef unsigned long long llong;

#define MAX 200001

int main()
{
  llong N, P;
  char S[MAX];
  llong mod = 0, ans = 0;
  llong T[MAX], M[MAX];
  M[0] = 1;
  T[0] = 1;

  scanf("%llu%llu", &N, &P);

  for (llong i = 1; i < P; i++)
  {
    M[i] = 0;
  }

  scanf("%s", S);
  if (P == 2 || P == 5)
  {
    for (int i = 1; i <= N; i++)
    {
      if ((S[i - 1] - '0') % P == 0)
      {
        ans += i;
      }
    }
  }
  else
  {

    for (llong i = 1; i < N; i++)
    {
      T[i] = (T[i - 1] * 10) % P;
    }

    for (llong i = 0; i < N; i++)
    {
      mod = (mod + (S[N - 1 - i] - '0') * T[i]) % P;
      ans += M[mod];
      M[mod]++;
    }
  }
  printf("%llu", ans);

  return 0;
}