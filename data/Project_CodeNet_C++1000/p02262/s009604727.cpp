#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

namespace {

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
  int G[100];
  G[0] = 1;
  for (int i = 0; i < 100; ++i) {
    G[i + 1] = 3 * G[i] + 1;
    ++m;
    if (G[i + 1] >= n) {
      break;
    }
  }
  sort(G, G + m, greater<int>());

  cout << m << endl;
  for (int i = 0; i < m; ++i) {
    if (i > 0) printf(" ");
    printf("%d", G[i]);
  }
  printf("\n");

  for (int i = 0; i < m; ++i) {
    cnt += InsertionSort(a, n, G[i]);
  }

  return cnt;
}

}  // namespace

int main() {
  int n;
  int a[1000000];

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  const int cnt = ShellSort(a, n);

  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
  return 0;
}