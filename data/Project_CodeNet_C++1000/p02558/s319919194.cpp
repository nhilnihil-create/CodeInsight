#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

constexpr int DEBUG = 0;

// Verified: AOJ-DSL1A, AGC002D
class UFSet {
 private:
  vector<int> ranks;
  vector<int> prevs;
  vector<int> sizes;

 public:
  UFSet(int n) : ranks(n), prevs(n), sizes(n) {
    for (int i = 0; i < n; i++) prevs[i] = i;
    for (int i = 0; i < n; i++) sizes[i] = 1;
  }

  // Returns an ID of a set which x belongs to.
  int Find(int x) {
    if (x != prevs[x]) prevs[x] = Find(prevs[x]);
    return prevs[x];
  }

  // Merges a set which x blongs to and a set which y belongs to.
  void Union(int x, int y) {
    int x_root = Find(x);
    int y_root = Find(y);
    if (ranks[x_root] > ranks[y_root]) {
      prevs[y_root] = prevs[x_root];
      sizes[x_root] += sizes[y_root];
    } else if (ranks[x_root] < ranks[y_root]) {
      prevs[x_root] = prevs[y_root];
      sizes[y_root] += sizes[x_root];
    } else if (prevs[x_root] != prevs[y_root]) {
      prevs[y_root] = prevs[x_root];
      ranks[x_root]++;
      sizes[x_root] += sizes[y_root];
    }
  }

  // Returns a size of a set which x belongs to.
  int Size(int x) {
    return sizes[Find(x)];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  UFSet uf_set(n);
  for (int q_index = 0; q_index < q; q_index++) {
    int t, v1, v2;
    cin >> t >> v1 >> v2;
    if (t == 0) {
      uf_set.Union(v1, v2);
    } else {
      if (uf_set.Find(v1) == uf_set.Find(v2)) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
  }
}