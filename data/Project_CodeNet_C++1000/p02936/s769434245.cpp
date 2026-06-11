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

struct Node {
  LL cnt = 0;
  vector<int> es;
};

int N, Q;
vector<Node> G;

void dfs(int v, int parent, LL cnt) {
  G[v].cnt += cnt;
  for (int u : G[v].es) {
    if (u == parent) continue;
    dfs(u, v, G[v].cnt);
  }
}

int main() {
  cin >> N >> Q;
  G.resize(N);
  for (int i = 0; i < N-1; ++i) {
    int a, b; cin >> a >> b; --a, --b;
    G[a].es.push_back(b);
    G[b].es.push_back(a);
  }

  for (int i = 0; i < Q; ++i) {
    int p, x; cin >> p >> x; --p;
    G[p].cnt += x;
  }

  dfs(0, -1, 0);

  for (int i = 0; i < N; ++i) cout << G[i].cnt << " ";
  cout << endl;
}
