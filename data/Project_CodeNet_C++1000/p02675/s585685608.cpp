#include <bits/stdc++.h>

int main() {
  int N;
  scanf("%d", &N);
  int v = N % 10;
  if (v == 2 || v == 4 || v == 5 || v == 7 || v == 9)
    printf("hon\n");
  else if (v == 3)
    printf("bon\n");
  else printf("pon\n");
}
