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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, n){
    cin >> p.at(i);
    p.at(i)--;
  }
  vector<int> c(n);
  rep(i, n) cin >> c.at(i);

  vector<ll> loopscore(n, 0);
  vector<int> loopsize(n, 0);
  rep(i, n){
    int sz = 1, pos = p.at(i);
    ll add = c.at(pos);
    while(pos != i){
      pos = p.at(pos);
      add += c.at(pos);
      sz++;
    }
    loopscore.at(i) = add;
    loopsize.at(i) = sz;
  }

  ll ans = -1e18;
  rep(i, n){
    int now = p.at(i);
    ll add = c.at(now);
    ans = max(ans, add);
    if(loopscore.at(i) <= 0 || loopsize.at(i) >= k){
      int co = 1;
      while(now != i && co < k){
        now = p.at(now);
        add += c.at(now);
        ans = max(ans, add);
        co++;
      }
    }else{
      int lc = k/loopsize.at(i)-1;
      add = loopscore.at(i)*lc;
      ans = max(ans, add);
      now = i;
      rep(j, k-lc*loopsize.at(i)){
        now = p.at(now);
        add += c.at(now);
        ans = max(ans, add);
      }
    }
  }

  cout << ans << endl;
  return 0;
}