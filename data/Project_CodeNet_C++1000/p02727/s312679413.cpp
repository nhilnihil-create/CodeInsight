#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int x, y; cin >> x >> y;
  int a, b, c; cin >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  for(int i = 0; i < a; i++) cin >> p[i];
  for(int i = 0; i < b; i++) cin >> q[i];
  for(int i = 0; i < c; i++) cin >> r[i];
  sort(p.begin(), p.end(), greater<ll>());
  sort(q.begin(), q.end(), greater<ll>());
  priority_queue<ll> que;
  for(int i = 0; i < x; i++) que.push(p[i]);
  for(int i = 0; i < y; i++) que.push(q[i]);
  for(int i = 0; i < c; i++) que.push(r[i]);
  ll ans = 0;
  for(int i = 0; i < x+y; i++){
    ll app = que.top(); que.pop();
    ans += app;
  }
  cout << ans << endl;
}
  