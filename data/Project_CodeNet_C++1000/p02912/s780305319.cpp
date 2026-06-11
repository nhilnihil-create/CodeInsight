#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n,m;
  cin >> n >> m;
  priority_queue<double> a;
  rep(i,n) {
    double t;
    cin >> t;
    a.push(t);
  }

  rep(i,m) {
    double k;
    k = a.top();
    a.pop();
    a.push(k/2);
  }

  ll ans = 0;
  rep(i,n) {
    ans += (ll) a.top();
    a.pop();
  }
  cout << ans << endl;
  return 0;
}
