#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll x, y, a, b, c;
  cin >> x >> y >> a >> b >> c;
  vector<ll> p(a), q(b), r(c);
  rep(i,a) cin >> p[i];
  rep(i,b) cin >> q[i];
  rep(i,c) cin >> r[i];
  sort(p.rbegin(),p.rend());
  sort(q.rbegin(),q.rend());
  sort(r.rbegin(),r.rend());
  vector<ll> px(x), qy(y);
  rep(i,x) px[i] = p[i];
  rep(i,y) qy[i] = q[i];
  ll ans = 0;
  int cnta=0, cntb=0, cntc=0; 
  rep(i,x+y){
    if(px[cnta] >= qy[cntb] && px[cnta] >= r[cntc]){
      ans += px[cnta];
      cnta++;
    }
    else if(qy[cntb] >= px[cnta] && qy[cntb] >= r[cntc]){
      ans += qy[cntb];
      cntb++;
    }
    else {
      ans += r[cntc];
      cntc++;
    }
  }
  cout << ans << endl;
}
