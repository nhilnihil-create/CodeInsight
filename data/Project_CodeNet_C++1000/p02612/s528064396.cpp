#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; scanf("%d", &n);
  printf("%d\n", (n + 999) / 1000 * 1000 - n);
  return 0;
}