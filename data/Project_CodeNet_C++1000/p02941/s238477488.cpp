#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<ll,ll>;

int main(){
  ll n, l, m, r, s, c, d = 0;
  cin >> n;
  ll a[n], b[n];
  priority_queue<P> que;
  rep(i,n) cin >> a[i];
  rep(i,n) {
    cin >> b[i];
    que.push(P(b[i],i));
  }
  while(!que.empty()) {
    P p = que.top(); que.pop();
    m = p.second;  l = (m-1+n) % n, r = (m+1) % n;
    s = b[l] + b[r]; c = min(b[m]/s,(b[m]-a[m])/s);
    if(c > 0) {
      b[m] -= s*c; que.push(P(b[m],m)); d += c;
    } 
  }
  rep(i,n) {
    if(a[i] != b[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << d << endl;
  return 0;
}