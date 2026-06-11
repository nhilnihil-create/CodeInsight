#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int m = 61;
int n;
vector<bitset<m>> gaussian_elimination(vector<bitset<m>> b) {
  vector<bitset<m>> c(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) c[i][j] = b[i][m - 1 - j];
  }
  int x = 0;
  for (int i = 0; i < n && x < m; i++, x++) {
    int pivot = -1;
    for (int j = i; j < n; j++) {
      if (c[j][x]) {
        pivot = j;
        break;
      }
    }
    if (pivot == -1) {
      i--;
      continue;
    }
    swap(c[pivot], c[i]);
    for (int j = i + 1; j < n; j++) {
      if (c[j][x]) c[j] ^= c[i];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) b[i][j] = c[i][m - 1 - j];
  }
  return b;
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  vector<long long> a(n);
  vector<bitset<m>> b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = bitset<m>(a[i]);
  }
  long long x = 0;
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += b[i][j];
    }
    if (cnt % 2 == 0) continue;
    x += 1LL << j;
    for (int i = 0; i < n; i++) {
      b[i][j] = 0;
    }
  }
  b = gaussian_elimination(b);
  bitset<m> y;
  for (int j = m - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      if (b[i][j] && y.to_ullong() < (y ^ b[i]).to_ullong()) {
        y ^= b[i];
        break;
      }
    }
  }
  cout << x + ((y.to_ullong()) << 1) << endl;
  return 0;
}