#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

LL mul(LL a, LL b) { return (a * b) % kMod; }

LL dfs(int i, int parent, const vector<vector<int>>& G, int K) {
  int num_color = (parent < 0) ? K - 1 : K - 2;
  LL total = 1;
  for (int v : G[i]) {
    if (v == parent) continue;

    total = mul(total, num_color);
    --num_color;

    total = mul(total, dfs(v, i, G, K));
  }
  return total;
}

int main() {
  int N, K; cin >> N >> K;
  vector<vector<int>> G(N);
  for (int i = 0; i < N-1; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  for (int i = 0; i < N; ++i) {
    if (G[i].size() > K) {
      cout << 0 << endl;
      return 0;
    }
  }

  LL total = mul(K, dfs(0, -1, G, K));
  cout << total << endl;
}
