#include <cstdio>
using namespace std;

const int N = 1000000;
const int M = 100;

int cnt = 0;

void insertionsort(int a[], int n, int g) {
  for (int i = g; i < n; i++) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
}

int main() {
  int n, a[N];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int m, g[M];
  g[0] = 1;
  for (int i = 1; ; i++) {
    g[i] = 3 * g[i - 1] + 1;
    if (g[i] >= n || i >= 100) {
      m = i;
      break;
    }
  }
  for (int i = m - 1; i >= 0; i--) {
    insertionsort(a, n, g[i]);
  }

  printf("%d\n", m);
  for (int i = m - 1; i >= 0; i--) printf("%d ", g[i]);
  printf("\n%d\n", cnt);
  for (int i = 0; i < n; i++) printf("%d\n", a[i]);
  return 0;
}