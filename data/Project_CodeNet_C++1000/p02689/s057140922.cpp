#include <iostream>
#include <vector>

using namespace std;
typedef long long llong;

#define MAX 100001
const llong mod = 1000000000 + 7;

int main()
{
  int N, M;
  llong H[MAX];
  int a, b;
  vector<int> A[MAX];
  int ans = 0;

  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &H[i]);
  }

  for (int i = 0; i < M; i++)
  {
    scanf("%d%d", &a, &b);
    A[a].push_back(b);
    A[b].push_back(a);
  }

  for (int i = 1; i <= N; i++)
  {
    vector<int> X = A[i];
    int flag = 1;
    for (int x : X)
    {
      if (H[x - 1] >= H[i - 1])
      {
        flag = 0;
        break;
      }
    }
    if (flag)
    {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}