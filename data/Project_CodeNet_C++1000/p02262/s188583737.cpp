#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void insertionSort(int a[], int n, int g) {
  for (int i=g; i<n; i++) {
    int v = a[i];
    int j = i - g;
    while (j >= 0 && a[j] > v) {
      a[j+g] = a[j];
      j -= g;
      cnt++;
    }
    a[j+g] = v;
  }
}

void shellSort(int a[], int n) {
  vector<int> G;
  int h = 1;
  while (h <= n) {
    G.push_back(h);
    h = 3 * h + 1;
  }

  for (int i=G.size()-1; i>=0; i--)
    insertionSort(a, n, G[i]);

  // print info
  cout << G.size() << endl;
  if (G.size() > 0) {
    for (int i=G.size()-1; i>0; i--)
      cout << G[i] << " ";
    cout << G[0] << endl;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i=0; i<n; i++) cin >> a[i];

  shellSort(a, n);

  cout << cnt << endl;

  for (int i=0; i<n; i++) cout << a[i] << endl;;

  return 0;
}

