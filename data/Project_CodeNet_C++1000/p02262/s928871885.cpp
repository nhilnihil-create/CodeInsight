#include <iostream>
using namespace std;

int cnt = 0;

void insertionSort(int a[], int n, int m) {
  for (int i = m; i < n; i++) {
    int key = a[i];
    int j = i - m;
    while (j >= 0 && a[j] > key) {
      a[j + m] = a[j];
      j -= m;
      ++cnt;
    }
    a[j + m] = key;
  }
}

int main() {
  int a[1000000];
  int n;
  int g[100] = {0};
  int glen = 0;

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  g[0] = 1;
  for (int i = 1; i < 100; i++) {
    int v = g[i - 1] * 3 + 1;

    if (v >= n) {
      glen = i;
      break;
    }

    g[i] = v;
  }

  cout << glen << endl;

  for (int i = glen - 1; i >= 1; i--) {
    cout << g[i] << ' ';
  }
  cout << g[0] << endl;

  for (int i = glen - 1; i >= 0; i--) {
    insertionSort(a, n, g[i]);
  }
  cout << cnt << endl;

  for (int i = 0; i < n; i++) {
    cout << a[i] << endl;
  }

  return 0;
}