#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  priority_queue<int> pq;
  rep(i, 0, n) {
    int a;
    cin >> a;
    pq.push(a);
  }

  rep(i, 0, m) {
    int x = pq.top();
    pq.pop();
    x /= 2;
    pq.push(x);
  }

  ll ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans << endl;
}
