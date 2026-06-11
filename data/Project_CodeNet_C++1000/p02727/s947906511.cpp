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
  priority_queue<int> p, q, r;
  vector<int> vp(a), vq(b);
  rep(i, a){
    cin >> vp.at(i);
  }
  rep(i, b){
    cin >> vq.at(i);
  }
  rep(i, c){
    int in;
    cin >> in;
    r.push(in);
  }

  ll ans = 0;
  sort(ALL(vp), greater<int>()); sort(ALL(vq), greater<int>());
  rep(i, x){
    ans += vp.at(i);
    p.push(vp.at(i) * -1);
  }
  rep(i, y){
    ans += vq.at(i);
    q.push(vq.at(i) * -1);
  }
  while(!r.empty()){
    int np = 2e9, nq = 2e9, nr;
    if(!p.empty()) np = p.top() * -1;
    if(!q.empty()) nq = q.top() * -1;
    nr = r.top();
    if(nr <= np && nr <= nq) break;
    if(np < nq){
      ans += nr - np;
      p.pop(); r.pop();
    }else{
      ans += nr - nq;
      q.pop(); r.pop();
    }
  }
  cout << ans << endl;
  return 0;
}