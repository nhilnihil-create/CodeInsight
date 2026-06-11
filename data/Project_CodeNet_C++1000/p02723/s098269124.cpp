#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX 7
const llong mod = 1000000000 + 7;

int main()
{
  char S[MAX];

  scanf("%s", S);

  if (S[2] == S[3] && S[4] == S[5])
    printf("Yes");
  else
    printf("No");

  return 0;
}