#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

constexpr int64_t kMod = 1e9+7;

int main() {
  int64_t N;
  cin >> N;
  vector<pair<int64_t, int64_t>> zs(N);
  vector<pair<int64_t, int64_t>> ws(N);
  for (int64_t n = 0; n < N; ++n) {
    int64_t x, y;
    cin >> x >> y;
    zs[n] = {x + y, n};
    ws[n] = {x - y, n};
  }
  sort(zs.begin(), zs.end());
  sort(ws.begin(), ws.end());
  
  int64_t dist_z = zs.back().first - zs.front().first;
  int64_t dist_w = ws.back().first - ws.front().first;

  cout << max(dist_z, dist_w) << endl;

  return 0;
}
