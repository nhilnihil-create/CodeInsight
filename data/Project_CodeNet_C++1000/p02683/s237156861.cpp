#include <bits/stdc++.h>
using namespace std;
int a[20][20], c[20], n, m, x;
int getbit(int num, int pos) { return (num >> pos) & 1; }
int getsum(int row) {
  int s[20] = {0}, money = 0;
  for (int i = 0; i < n; i++) {
    if (getbit(row, i) == 0) {
      money += c[i];
      for (int j = 0; j < m; j++) {
        s[j] += a[i][j];
      }
    }
  }
  for (int j = 0; j < m; j++) {
    if (s[j] < x) {
      money = -1;
      break;
    }
  }
  return money;
}
int main() {
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  int minm = INT_MAX;
  for (int i = 0; i < (1 << n); i++) {
    if (getsum(i) != -1) {
      minm = min(minm, getsum(i));
    }
  }
  if (minm == INT_MAX) minm = -1;
  cout << minm << endl;
  return 0;
}
