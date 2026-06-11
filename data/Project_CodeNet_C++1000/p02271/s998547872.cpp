#include<stdio.h>

bool exhaustiveSearch(int i, int n, int m, int A[]) {
  if (A[i] == m) return true;
  if (i >= n - 1) return false;
  return exhaustiveSearch(i + 1, n, m, A) || exhaustiveSearch(i + 1, n, m - A[i], A);
}

int main() {
  int i, n, A[20], q, m;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  scanf("%d", &q);
  for ( i = 0; i < q; i++ ) {
    scanf("%d", &m);
    if (exhaustiveSearch(0, n, m, A)) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }

  return 0;
}

