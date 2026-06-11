#include "bits/stdc++.h"
using namespace std;

int Solve(int n, vector<int> a, int d = 0) {
  vector<int> contrib(n); // contrib[i] = parity of Choose(n - 1, i)
  vector<int> twomul(n); // how many times a number can be divided by 2
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 1 && j % 2 == 0) {
      twomul[i]++;
      j /= 2;
    }
  }
  for (int i = 1; i < n; i++) {
    twomul[i] += twomul[i - 1];
  }
  for (int i = 0; i < n; i++) {
    int candiv = twomul[n - 1] - twomul[i] - twomul[n - 1 - i];
    if (candiv > 0) {
      contrib[i] = 0;
    } else {
      contrib[i] = 1;
    }
  }
  int xorall = 0;
  for (int i = 0; i < n; i++) {
    if (contrib[i]) {
      xorall ^= a[i] % 2;
    }
  }
  if (xorall == 1) {
    return 1;
  }
  if (d == 1) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) {
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    a[i] /= 2;
  }
  return 2 * Solve(n, a, 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  string s;
  cin >> s;

  vector<int> a;
  for (auto &i : s) {
    a.emplace_back(i - '1');
  }

  cout << Solve(n, a) << "\n";
  return 0;
}
