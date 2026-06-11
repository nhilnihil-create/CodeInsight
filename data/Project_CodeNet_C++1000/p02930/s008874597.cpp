#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int a[N][N];

int main() {
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      int xr = i ^ j;
      for (int k = 0; k < 20; k++)
        if ((xr >> k) & 1) {
          a[i][j] = k + 1;
          break;
        }
    }
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1)
        printf(" ");
      printf("%d", a[i][j]);
    }
    puts("");
  }
  return 0;
}