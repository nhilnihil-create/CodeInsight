#include <iostream>
using namespace std;

typedef long long ll;

int levels[501][501];

void solve(int from, int to, int level) {
  if (from == to) return;
  int mid = (from+to)/2;
  for (int i = from; i <= mid; ++i) {
    for (int j = mid+1; j <= to; ++j) {
      levels[i][j] = level;
    }
  }
  if (to-from == 1) return;
  solve(from, mid, level+1);
  solve(mid+1, to, level+1);
}

int main() {
  int n;
  cin >> n;
  solve(0, n-1, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      cout << levels[i][j] << " ";
    }
    cout << endl;
  }
}

