#include <cstdio>
#include <iostream>

using namespace std;

namespace {

const int G[14] = {
  1,
  4,
  13,
  40,
  121,
  364,
  1093,
  3280,
  9841,
  29524,
  88573,
  265720,
  797161,
  2391484,
};

int InsertionSort(int* a, int n, int g) {
  int cnt = 0;
  for (int i = g; i < n; ++i) {
    const int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
  return cnt;
}

int ShellSort(int* a, int n) {
  int cnt = 0;
  int m = 0;
  for (int i = 0; i < 100; ++i) {
    ++m;
    if (G[i + 1] >= n) {
      break;
    }
  }

  printf("%d\n", m);
  for (int i = m - 1; i >= 0; --i) {
    if (i < m - 1) printf(" ");
    printf("%d", G[i]);
  }
  printf("\n");

  for (int i = 0; i < m; ++i) {
    cnt += InsertionSort(a, n, G[m - i - 1]);
  }

  return cnt;
}

}  // namespace

int main() {
  int n;
  int a[1000000];

  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  const int cnt = ShellSort(a, n);
  printf("%d\n", cnt);
  for (int i = 0; i < n; ++i) {
    printf("%d\n", a[i]);
  }
  return 0;
}