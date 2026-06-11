#include <cstdio>
#include <math.h>

using namespace std;

int main(void)
{
  int i, sum, dig;
  int a, b;

  while (scanf("%d %d", &a, &b) != EOF) {
    sum = a + b;
    dig = 1;
    for (i = 1; i < 7; i++) {
      if (sum - pow(10, i) < 0) break;
      dig++;
    }
    printf("%d\n", dig);
  }

  return 0;
}