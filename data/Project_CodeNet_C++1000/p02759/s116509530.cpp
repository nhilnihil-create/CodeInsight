#include <cstdio>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int N;
  scanf("%d", &N);

  printf("%d", N % 2 == 0 ? N / 2 : N / 2 + 1);

  return 0;
}