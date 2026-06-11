#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX 4
const llong mod = 1000000000 + 7;

int main()
{
  char S[MAX];
  char Ans[2][MAX] = {"ABC", "ARC"};
  int ans;

  scanf("%s", S);

  ans = S[1] == 'B' ? 1 : 0;

  printf("%s", Ans[ans]);

  return 0;
}