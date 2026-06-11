#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void rec(int from, int n, int v, vector<vector<int>>& r) {
  if (n < 2)
    return;
  int m = n / 2;
  for (int i = from; i < from + m; ++i) {
    for (int j = from + m; j < from + n; ++j) {
      r[i][j] = v;
    }
  }
  rec(from, m, v + 1, r);
  rec(from + m, n - m, v + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> level(n, vector<int>(n));

  rec(0, n, 1, level);

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (j > i + 1)
        cout << " ";
      cout << level[i][j];
    }
    cout << "\n";
  }

  return 0;
}
