#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long llong;

#define MAX 200001
const llong mod = 1000000000 + 7;

int main()
{
  char S[MAX];
  int U[2019];

  scanf("%s", S);

  U[0] = 1;

  int current = 0;
  int ans = 0;
  int len = strlen(S);
  int T[MAX];
  T[0] = 1;
  for (int i = 1; i < len; i++)
  {
    T[i] = (T[i - 1] * 10) % 2019;
  }

  for (int i = 0; i < len; i++)
  {
    current = (current + (S[len - 1 - i] - '0') * T[i]) % 2019;
    ans += U[current];
    U[current]++;
  }

  printf("%d", ans);

  return 0;
}