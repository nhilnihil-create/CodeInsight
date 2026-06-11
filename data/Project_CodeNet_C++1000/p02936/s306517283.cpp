#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> graph[n];
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vector<int> cnt(n);
  rep(i, q) {
    int p, x;
    cin >> p >> x;
    --p;
    cnt[p] += x;    
  }
  //rep(i, n) cout << cnt[i] << '\n';
  int root = 0;
  vector<int> parent(n, -1);
  vector<int> order;
  stack<int> stk;
  stk.push(root);
  while (!stk.empty()) {
    int cur = stk.top();
    stk.pop();
    order.push_back(cur);
    for (auto next : graph[cur]) {
      if (next == parent[cur]) continue;
      parent[next] = cur;
      cnt[next] += cnt[cur];
      stk.push(next);
    }
  }
  rep(i, n) cout << cnt[i] << ' ';  
  return 0;
}

/*
root = 1
parent = [0] * (N+1)
order = []
stack = [root]
while stack:
    cur = stack.pop()
    order.append(cur)
    for next in graph[cur]:
        if next == parent[cur]:
            continue
        parent[next] = cur
        stack.append(next)
*/