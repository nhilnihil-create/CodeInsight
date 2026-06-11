#include <cstdio>
#define access(i) A[i / 3][i % 3]

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int A[3][3];
  int N, b;
  int flag = 0;
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &access(i));
  }

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &b);
    for (int j = 0; j < 9; j++)
    {
      if (access(j) == b)
        access(j) = 0;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    if (A[i][0] == 0 && A[i][1] == 0 && A[i][2] == 0)
      flag = true;
    if (A[0][i] == 0 && A[1][i] == 0 && A[2][i] == 0)
      flag = true;
  }
  if (A[0][0] == 0 && A[1][1] == 0 && A[2][2] == 0)
    flag = true;
  if (A[0][2] == 0 && A[1][1] == 0 && A[2][0] == 0)
    flag = true;

  if (flag)
    printf("Yes");
  else
    printf("No");

  return 0;
}