#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main() {
  int N, D; cin >> N >> D;

  vector<vector<int>> points(N, vector<int>(D));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < D; j++) {
      cin >> points[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int k = i + 1; k < N; k++) {
      int cur = 0;
      for (int j = 0; j < D; j++) {
        cur += pow(points[i][j] - points[k][j], 2);
      }

      double v = sqrt(cur);
      if (v - floor(v) == 0)
        ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
