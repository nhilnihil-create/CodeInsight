#include <iostream>
#include <vector>
using namespace std;

long long cnt = 0;
vector<int> g;

void insertionSort(int a[], int n, int g) {
  int v;
  for (int i = g; i < n; i++) {
    v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j + g] = a[j];
      j -= g;
      cnt++;
    }
    a[j + g] = v;
  }
}

void shellSort(int a[], int n) {
  for (int h = 1;;) {
    if (h > n) break;
    g.push_back(h);
    h = 3 * h + 1;
  }
  for (int i = g.size() - 1; 0 <= i; --i) {
    insertionSort(a, n, g[i]);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  shellSort(a, n);
  cout << g.size() << endl;
  for (int i = g.size() - 1; 0 <= i; --i) {
    cout << g[i] << ((i == 0) ? '\n' : ' ');
  }
  cout << cnt << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << endl;
  }
}

