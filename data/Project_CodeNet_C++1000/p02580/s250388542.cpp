#include <set>
#include <vector>
#include <iostream>

using namespace std;

#define int long long

const int N = 3e5 + 10;

int c[N];
vector<int> r[N];
set<pair<int, int>> sc;

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);    
  int h, w, m;
  cin >> h >> w >> m;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    r[x].push_back(y);
    ++c[y];    
  }
  for (int i = 1; i < N; ++i) {
    sc.insert({c[i], i});
  }
  int ans = 0;
  for (int i = 1; i < N; ++i) {
    for (int &y : r[i]) {
      sc.erase(sc.find({c[y], y}));
      sc.insert({c[y] - 1, y});
    }
    auto it = sc.end();
    --it;
    ans = max(ans, it->first + (int)r[i].size());
    for (int &y : r[i]) {
      sc.erase(sc.find({c[y] - 1, y}));
      sc.insert({c[y], y});
    }
  }
  cout << ans;
  return 0;
}
