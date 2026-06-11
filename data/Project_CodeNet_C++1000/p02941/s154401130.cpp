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
  for (int i = 0; i < n; i++) pq.emplace(state[i], i);
  long long ans = 0;
  while (!pq.empty()) {
    auto last = pq.top(); pq.pop();
    int val = last.first;
    int ind = last.second;
    if (state[ind] != val) continue;
    if (val == init[ind]) continue;
    if (val < init[ind]) { ans = -1; break; }
    int left = state[(ind + (n - 1)) % n];
    int right = state[(ind + 1) % n];
    int add = left + right;
    int rem = val - init[ind];
    if (rem < add) { ans = -1; break; }
    ans += rem / add;
    state[ind] = val - add*(rem / add);
    pq.emplace(state[ind], ind);
  }
  cout << ans << "\n";
  return 0;
}
