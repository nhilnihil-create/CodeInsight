#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

class UFTree {
  vector<int> m_parent;
  vector<int> m_height;
  vector<int> m_size;

 public:
  UFTree(int size) {
    for (int i = 0; i < size; i++) {
      m_parent.push_back(i);
      m_height.push_back(0);
      m_size.push_back(1);
    }
  }

  int root(int node) {
    if (m_parent[node] == node) {
      return node;
    }
    return m_parent[node] = root(m_parent[node]);
  }
  void merge(int n0, int n1) {
    int r0 = root(n0), r1 = root(n1);
    if (r0 == r1) {
      return;
    }
    if (m_height[r0] < m_height[r1]) swap(r0, r1);
    if (m_height[r0] == m_height[r1]) m_height[r0]++;
    m_parent[r1] = r0;
    m_size[r0] += m_size[r1];
  }
  int size(int node) { return m_size[root(node)]; }
};

int main() {
  int N, K;
  cin >> N >> K;
  K--;

  vector<int> p(N), c(N);
  UFTree uft(N);
  rep(i, p.size()) {
    cin >> p[i];
    p[i]--;
    uft.merge(i, p[i]);
  }
  for (auto &elm : c) {
    cin >> elm;
  }

  vector<int64_t> s(N, 0);
  rep(i, N) { s[uft.root(i)] += c[i]; }

  int64_t result = numeric_limits<int64_t>::min();
  rep(i, N) {
    int curr = p[i];
    int T = uft.size(curr);
    int64_t score = c[curr];
    int R = K % T;
    rep(j, T) {
      if (j <= R) {
        chmax(result, score + max((int64_t)0, s[uft.root(curr)]) * (K / T));
      } else if (K >= T) {
        chmax(result, score);
      }
      curr = p[curr];
      score += c[curr];
    }
  }
  cout << result << endl;

  return 0;
}