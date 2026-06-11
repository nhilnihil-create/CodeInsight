#include <cstdio>
#include <string>

using namespace std;
typedef long long llong;

#define MAX 10
const llong mod = 1000000000 + 7;

int main()
{
  int N, M;
  int S[MAX], C[MAX];
  scanf("%d%d", &N, &M);

  for (int i = 0; i < M; i++)
  {
    scanf("%d%d", &S[i], &C[i]);
  }

  int i;
  for (i = 0; i < 1000; i++)
  {
    string str = to_string(i);
    int flag = 1;
    if (str.size() != N)
      continue;
    for (int j = 0; j < M; j++)
    {
      if (str[S[j] - 1] - '0' != C[j])
        flag = 0;
    }
    if (flag)
      break;
  }
  if (i == 1000)
    i = -1;

  printf("%d", i);

  return 0;
}