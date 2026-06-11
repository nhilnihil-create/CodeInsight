#include <stdio.h>
#include <limits.h>

int main(void) {
  long i, n, temp, sum = 0;
  long min = LONG_MAX, max = LONG_MIN;

  scanf("%ld", &n);

  for (i = 0; i < n; i++) {
    scanf("%ld", &temp);

    sum += temp;

    if (temp < min)
      min = temp;
    if (temp > max)
      max = temp;
  }

  printf("%ld %ld %ld\n", min, max, sum);

  return 0;
}