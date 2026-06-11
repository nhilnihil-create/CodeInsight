#include <bits/stdc++.h>
using namespace std;

int n;
int mat[500][500];

void rec(int l, int r, int c) {
  if (r - l == 1) return;
  int m = (l + r) / 2;
  for (int i = l; i < m; ++i) {
    for (int j = m; j < r; ++j) {
      mat[i][j] = c;
      mat[j][i] = c;
    }
  }
  rec(l, m, c + 1);
  rec(m, r, c + 1);
}

int main() {
  cin >> n;
  rec(0, n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }
}