#include <stdio.h>

using namespace std;
typedef long long llong;

#define MAX
const llong mod = 1000000000 + 7;

int main()
{
  int n, i;
  char units[3][4] = {"bon", "pon", "hon"};
  scanf("%d", &n);

  switch (n % 10)
  {
  case 3:
    i = 0;
    break;
  case 0:
  case 1:
  case 6:
  case 8:
    i = 1;
    break;
  default:
    i = 2;
    break;
  }

  printf("%s\n", units[i]);
  return 0;
}