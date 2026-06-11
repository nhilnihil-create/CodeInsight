#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using lpair = pair<llong, llong>;

#define ALL(x) x.begin(), x.end()

constexpr llong mod = 1e9+7;
constexpr llong inf = mod * mod;

struct node {
  llong idx;
  llong sum = 0;
  vector<llong> children;

  node() = default;
  node(llong idx): 
    idx(idx)
  {}
};

llong N, Q;
vector<node> tree;

void dfs(llong now, llong par) {
  for (auto child: tree[now].children) {
    if (child == par) continue;
    tree[child].sum += tree[now].sum;
    dfs(child, now);
  }
}

int main() {

  cin >> N >> Q;
  tree.resize(N + 1);
  for (int i = 0; i < N - 1; i++) {
    llong a, b;
    cin >> a >> b;
    tree[a].children.push_back(b);
    tree[b].children.push_back(a);
  }
  for (int i = 0; i < Q; i++) {
    llong p, x;
    cin >> p >> x;
    tree[p].sum += x;
  }

  dfs(1, -1);
  for (int i = 1; i <= N; i++) {
    cout << tree[i].sum << " \n"[i == N];
  }

  return 0;
}