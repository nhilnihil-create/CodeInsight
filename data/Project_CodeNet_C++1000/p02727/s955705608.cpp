#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int x, y;
  cin >> x >> y;
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> p(a);
  rep(i, a) cin >> p.at(i);
  vector<int> q(b);
  rep(i, b) cin >> q.at(i);
  vector<int> r(c);
  rep(i, c) cin >> r.at(i);
  sort(ALL(p), greater<int>());
  sort(ALL(q), greater<int>());

  priority_queue<int> que;
  rep(i, x) que.push(p.at(i));
  rep(i, y) que.push(q.at(i));
  rep(i, c) que.push(r.at(i));

  ll ans = 0;
  rep(i, x+y){
    ans += que.top();
    que.pop();
  }
  cout << ans << endl;
  return 0;
}