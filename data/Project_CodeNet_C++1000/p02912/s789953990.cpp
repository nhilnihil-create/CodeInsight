#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int> a;
  rep(i, n) {
    int x;
    cin >> x;
    a.push(x);
  }
  while (m) {
    int t = a.top();
    a.pop();
    a.push(t/2);
    --m;
  }
  ll ans = 0;
  rep(i, n) {
    ans += a.top();
    a.pop();
  }
  cout << ans << '\n';

  return 0;
}