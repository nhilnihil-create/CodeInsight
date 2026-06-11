#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int x,y,a,b,c;
  cin >> x >> y >> a >> b >> c;
  
  vector<int>p(a);
  vector<int>q(b);
  vector<int>r(c);
  rep(i,0,a) cin >> p[i];
  rep(i,0,b) cin >> q[i];
  rep(i,0,c) cin >> r[i];
  sort(p.begin(),p.end());
  reverse(p.begin(),p.end());
  sort(q.begin(),q.end());
  reverse(q.begin(),q.end());
  
  rep(i,0,a-x) p.pop_back();
  rep(i,0,b-y) q.pop_back();
  
  rep(i,0,x) r.push_back(p[i]);
  rep(i,0,y) r.push_back(q[i]);
  sort(r.begin(),r.end());
  reverse(r.begin(),r.end());
  ll ans = 0;
  rep(i,0,x+y) ans += r[i];
  cout << ans << endl;
}