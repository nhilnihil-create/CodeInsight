#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int n,m;


int main() {
  cin >> n >> m;
  priority_queue<ll> a;
  rep(i,n) {
    ll x;cin >> x;
    a.push(x);
  }
  
  rep(i,m) {
    ll t = a.top(); a.pop();
    a.push(t/2);
  }
  ll ans = 0;
  rep(i,n) {
    ans += a.top();
    a.pop();
  }
  cout << ans << endl;
  return 0;
}