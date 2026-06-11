#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  llong N;
  int K;
  scanf("%lld%d", &N, &K);

  int ans = 0;
  while (N > 0)
  {
    N /= K;
    ans++;
  }

  printf("%d", ans);

  return 0;
}