#include <iostream>
#include <queue>
#define rep(i,n) for(int i=0; i<(n); ++i)
typedef long long ll;
using namespace std;

int main(){

  ll x, y, a, b, c;
  ll ans = 0;

  cin >> x >> y >> a >> b >> c;

  priority_queue<ll> quep, queq, quer;
  queq.push(0);
  rep(i,a){
    ll p;
    cin >> p;
    quep.push(p);
  }
  queq.push(0);
  rep(i,b){
    ll q;
    cin >> q;
    queq.push(q);
  }
  quer.push(0);
  rep(i,c){
    ll r;
    cin >> r;
    quer.push(r);
  }

  ll r, g, n;
  r = g = n = 0;
  while(r+g+n < x+y){
    ll rtop, gtop, ntop;
    rtop = quep.top(); gtop = queq.top(); ntop = quer.top();
    if(x <= r) rtop = 0;
    if(y <= g) gtop = 0;

    if(rtop > max(gtop,ntop)){
      ++r; ans += rtop;
      quep.pop();
    }
    else if(gtop > ntop){
      ++g; ans += gtop;
      queq.pop();
    }
    else{
      ++n; ans += ntop;
      quer.pop();
    }
  }

  cout << ans << endl;
  return 0;
}
