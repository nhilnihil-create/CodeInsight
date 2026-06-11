#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define int long long

signed main() {
  int n,m;
  cin >> n >> m;

  priority_queue<int> que;
  rep(i,n) {
    int a; cin >> a;
    que.push(a);
  }

  while(m--) {
    int v = que.top();
    que.pop();
    v/=2;
    que.push(v);
  }

  int ans = 0;
  while(!que.empty()) {
    int v = que.top();
    que.pop();
    ans += v;
  }
  cout << ans << '\n';
}