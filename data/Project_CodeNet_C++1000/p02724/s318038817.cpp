#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  llong X;
  scanf("%lld", &X);
  llong gold1, gold2;

  gold1 = X / 500;
  gold2 = (X - 500 * gold1) / 5;

  printf("%lld", 1000 * gold1 + 5 * gold2);

  return 0;
}