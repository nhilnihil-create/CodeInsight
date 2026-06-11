#include <stdio.h>

int main() {
  int h1, m1, h2, m2, k, minute;
  scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
  m2 = m2 + h2 * 60;
  m1 = m1 + h1 * 60;

  if(m2 >= m1) minute = m2  - m1;
  else minute = m1 - m2;
  printf("%d\n", minute - k);
  return 0;
}
