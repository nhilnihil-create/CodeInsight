#include <stdio.h>
#include <string.h>

using namespace std;
typedef long long llong;

#define MAX 11
const llong mod = 1000000000 + 7;

int main()
{
  int len = 0;
  char S[MAX], T[MAX + 1];
  scanf("%s", S);
  scanf("%s", T);

  len = strlen(S);
  for (int i = 0; i < len; i++)
  {
    if (S[i] != T[i])
    {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");

  return 0;
}