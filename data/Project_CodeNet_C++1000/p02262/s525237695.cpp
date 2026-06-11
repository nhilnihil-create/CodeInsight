#include <iostream>
#include <cmath>

using namespace std;

int insertionSort(int a[], int n, int g) {
  int i, j, v, cnt = 0;
  for (i = g; i < n ; i++) {
    v = a[i];
    j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j+g] = a[j];
      j = j - g;
      cnt++;
    }
    a[j+g] = v;
  }
  return cnt;
}

void shellSort(int a[], int n) {
  int i, cnt = 0;
  double l = ceil(log((double)n) / log(4.0));
  int m = l;
  if (m == 0) m = 1;
  int g[m];
  for (i = 0; i < m; i++) {
    if (i==m-1) g[i] = 1;
    else g[i] = pow(2, (m-i));
  }
  cout << m << endl;
  for (i = 0; i < m; i++) {
    if (i != 0) cout << " ";
    cout << g[i];
  }
  cout << endl;
  for (i = 0; i < m; i++) {
    cnt += insertionSort(a, n, g[i]);
  }
  cout << cnt << endl;
}

int main(void) {
  int i, j, n;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  shellSort(a, n);
  for (i = 0; i < n; i++) cout << a[i] << endl;
  return 0;
}