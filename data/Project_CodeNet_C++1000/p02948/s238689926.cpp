#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, o = 0;
  scanf("%d %d", &n, &m);
  vector<vector<int>> p(m);
  priority_queue<int> que;
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a > m) continue;
    p[m - a].push_back(b);
  }
  for(int i = m - 1; i >= 0; i--) {
    for(auto x : p[i]) que.push(x);
    if(!que.empty()) {
      auto q = que.top();
      que.pop();
      o += q;
    }
  }
  printf("%d\n", o);
}