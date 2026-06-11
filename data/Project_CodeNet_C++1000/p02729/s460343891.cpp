#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int N, M;
  scanf("%d%d", &N, &M);

  printf("%d", N * (N - 1) / 2 + M * (M - 1) / 2);

  return 0;
}