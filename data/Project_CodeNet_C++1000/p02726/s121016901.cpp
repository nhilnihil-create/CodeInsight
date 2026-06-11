#include <bits/stdc++.h>
using namespace std;

int x, y;

int sh(int i, int j) {
  int a, b;
  a = j - i;
  b = abs(x - i) + abs(y - j) + 1;
  return min(a, b);
}

int main() {
  int n;
  cin >> n >> x >> y;
  vector<int> k(n, 0);
  for(int i = 1; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
      k.at(sh(i, j))++;
    }
  }
  for(int i = 1; i < n; i++) cout << k.at(i) << endl;
}