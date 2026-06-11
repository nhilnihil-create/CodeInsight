#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
  int n,a;
  cin >> n;

  unordered_map<int, int> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (m.find(a) == m.end()) { m.emplace(a, 0); }
    m[a]++;
  }

  priority_queue<int> q;
  for (const auto& e : m) {
    q.push(e.second);
  }

  int count = n;
  for (int k = 1; k <= n; k++) {
    int max_pairs = count / k;
    int t;

    while (!q.empty() && (t = q.top()) > max_pairs) {
      // 可能な最大回数(max_pairs)を超える数値についてはカード枚数を減らす。
      // (すべての数値のカード枚数がmax_pairs以下の場合は、max_pairs回操作可能)
      q.pop();
      int diff = t - max_pairs;

      q.push(max_pairs);
      count -= diff;
      max_pairs = count / k;
    }

    cout << max_pairs << endl;
  }
}
