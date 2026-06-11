#include <iostream>
#include <vector>
#include <set>

using namespace std;

// |xj - xi| + |yj - yi|                                                                                                                                      
// xj + max(yj - xi - yi, -yj - xi + yi)                                                                                                                      

int main() {
  int N;
  cin >> N;
  set<int> plus, minus;
  int ans = 0;
  vector<pair<int, int>> points;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
  }
  sort(points.begin(), points.end(),
       [](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
  for (int i = 0; i < N; i++) {
    pair<int, int> point = points[i];
    int x = point.first;
    int y = point.second;
    if (i > 0) {
      int cand = max(x+y-*plus.begin(), x-y-*minus.begin());
      ans = max(ans, cand);
    }
    plus.insert(x+y);
    minus.insert(x-y);
  }
  cout << ans << endl;
}
