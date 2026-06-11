/*
 * Problem     : AOJ1172
 * Title       : Chebyshev's Theorem (チェビシェフの定理)
 * Author      : mizo0203
 * Copyright   : Your copyright free
 * Description : 素数・エラトステネスの篩
 */

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
bool a[246913];

void init() {
  int i, j;

  fill(a, a + 246913, true);
  a[0] = false;
  a[1] = false;
  for (i = 2; i < 246913; i++) {
    if (a[i]) {
      for (j = i * 2; j < 246913; j+=i) {
        a[j] = false;
      }
    }
  }

}

bool input() {
  scanf("%d", &n);
  if (!n)
    return false;
  return true;
}

int main() {
  int i, cnt;

  init();
  while (input()) {
    cnt = 0;
    for (i = n + 1; i <= 2 * n; i++) {
      if (a[i]) cnt++;
    }
    printf("%d\n", cnt);
  }

  return 0;
}