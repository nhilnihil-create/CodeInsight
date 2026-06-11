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

int N, K;
vector<vector<int>> G;

LL dfs(int v, int p, int d, LL c) {
  LL ans = c;
  c = (d == 0) ? K - 1 : K - 2;
  for (int u : G[v]) {
    if (u == p) continue;
    ans *= dfs(u, v, d + 1, c);
    ans %= kMod;
    --c;
  }
  return ans;
}

int main() {
  cin >> N >> K;
  G.resize(N);
  for (int i = 0; i < N-1; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << dfs(0, -1, 0, K) % kMod << endl;
}
