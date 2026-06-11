#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>
#include <limits>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> init(n);
  for (int i = 0; i < n; i++) cin >> init[i];
  vector<int> state(n);
  for (int i = 0; i < n; i++) cin >> state[i];
  priority_queue<pair<int, int>> pq;
  vector<int> visit(n);
  for (int i = 0; i < n; i++) {
    pq.emplace(state[i], i);
    visit[i] = 1;
  }
  long long ans = 0;
  while (!pq.empty()) {
    auto last = pq.top(); pq.pop();
    int val = last.first, ind = last.second;
    visit[ind] = 0;

    if (val == init[ind]) continue;
    if (val < init[ind]) { ans = -1; break; }
    int lind = (ind + (n - 1)) % n, rind = (ind + 1) % n;
    int left = state[lind];
    int right = state[rind];
    int add = left + right;
    int rem = val - init[ind];
    if (rem < add) { continue; }
    ans += rem / add;
    state[ind] = val - add*(rem / add);
    if (visit[lind] == 0) { pq.emplace(state[lind], lind); visit[lind] = 1; }
    pq.emplace(state[ind], ind); visit[ind] = 1;
    if (visit[rind] == 0) { pq.emplace(state[rind], rind); visit[rind] = 1; }
  }
  if (state != init) ans = -1;
  cout << ans << "\n";
  return 0;
}
