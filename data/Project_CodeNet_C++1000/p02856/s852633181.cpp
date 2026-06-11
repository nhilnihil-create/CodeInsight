#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i, n) for(int (i)=0; (i)< (n); ++i)
#define REPR(i, n) for(int (i)=(n); (i)>=0; --i)
#define FOR(i, n, m) for(int (i)=(n); (i)<(m); ++i)

int main(){
  int M;
  cin >> M;
  ll n = 0, s= 0;
  REP(i, M){
    ll d, c;
    cin >> d >> c;
    n+=c, s+= d*c;
  }
  ll ans = (9*n+s)/9;
  ll x = (9*n+s)%9;
  while(x < 10){
    x+=9;
    ans--;
  }
  cout << ans << endl;
  return 0;
}
