#include <iostream>

using namespace std;
typedef long long llong;

#define MAX 101
const llong mod = 1000000000 + 7;

int main()
{
  int N, K, d;
  int a, B[MAX];
  int ans = 0;

  cin >> N >> K;

  for (int i = 0; i < N; i++)
  {
    B[i] = 0;
  }

  for (int i = 0; i < K; i++)
  {
    cin >> d;
    for (int j = 0; j < d; j++)
    {
      cin >> a;
      B[a - 1]++;
    }
  }
  for (int i = 0; i < N; i++)
  {
    if (B[i] == 0)
      ans++;
  }

  printf("%d\n", ans);

  return 0;
}