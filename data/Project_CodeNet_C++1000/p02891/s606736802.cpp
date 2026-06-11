#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  int k;
  cin >> k;
  ll ans = 0;
  char m = 0;
  int c = 0;
  vector<pair<char, int>> vp;
  rep(i, s.size()){
    if(m != s.at(i)){
      // cerr << c << " " << m << endl;
      if(i != 0) vp.push_back(make_pair(m, c));
      c = 1;
      m = s.at(i);
    }else c++;
  }
  vp.push_back(make_pair(m, c));
  rep2(i, 1, vp.size()-1){
    ans += vp.at(i).second/2;
  }
  if(vp.size() == 1){
    ll t = (ll)vp.front().second * k;
    ans = t/2;
  }else if(vp.front().first != vp.back().first){
    ans += vp.front().second/2;
    ans += vp.back().second/2;
    ans *= k;
  }else{
    ans *= k;
    ans += vp.front().second/2;
    ans += vp.back().second/2;
    ans += (ll)(vp.front().second+vp.back().second)/2*(k-1);
  }
  cout << ans << endl;
  return 0;
}