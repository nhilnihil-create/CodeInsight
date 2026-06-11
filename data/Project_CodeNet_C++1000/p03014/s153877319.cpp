#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>
#include <numeric>
#include <random>


using namespace std;
typedef long long ll;

string grid[2048];

vector<int> rows[2048], cols[2048];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }
  for (int i = 0; i < n; i++) {
    rows[i].push_back(-1);
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') rows[i].push_back(j);
    }
    rows[i].push_back(m);
  }
  for (int i = 0; i < m; i++) {
    cols[i].push_back(-1);
    for (int j = 0; j < n; j++) {
      if (grid[j][i] == '#') cols[i].push_back(j);
    }
    cols[i].push_back(n);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == '#') continue;
      auto it = upper_bound(rows[i].begin(), rows[i].end(), j);
      int hi = it - rows[i].begin();
      it--;
      int lo = it - rows[i].begin();
      int aux = 0;
      aux += (rows[i][hi] - rows[i][lo]) - 1;
      it = upper_bound(cols[j].begin(), cols[j].end(), i);
      hi = it - cols[j].begin();
      it--;
      lo = it - cols[j].begin();
      aux += (cols[j][hi] - cols[j][lo]) - 1;
      res = max(res, aux);
    }
  }
  cout << res - 1<< endl;
  return 0;
}
