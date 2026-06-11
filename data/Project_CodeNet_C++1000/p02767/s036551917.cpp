#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX 100
const llong mod = 1000000000 + 7;

int main()
{
  int N, X[MAX];
  int ans = 100 * 100 * 100;

  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &X[i]);
  }

  sort(X, X + N);

  // 点P
  for (int i = X[0]; i <= X[N - 1]; i++)
  {
    int sum = 0;
    for (int j = 0; j < N; j++)
    {
      sum += (X[j] - i) * (X[j] - i);
    }

    ans = min(ans, sum);
  }

  printf("%d\n", ans);

  return 0;
}