#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  double L;
  double ans = 0;
  double I, J, K;
  scanf("%lf", &L);
  L = L / 3.0;
  printf("%.7lf", L * L * L);

  return 0;
}