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
  string s;
  cin >> s;
  vector<pair<char, int>> vp;
  vp.push_back({s.front(), 1});
  rep2(i, 1, s.size()){
    if(s.at(i) == s.at(i-1)) vp.back().second++;
    else vp.push_back({s.at(i), 1});
  }

  int k;
  cin >> k;
  ll ans = 0;
  rep2(i, 1, vp.size()-1) ans += (ll)vp.at(i).second/2*k;
  if(vp.size() == 1){
    ans += (ll)s.size()*k/2;
  }else if(vp.front().first == vp.back().first){
    ans += (ll)(vp.front().second+vp.back().second)/2*(k-1);
    ans += vp.front().second/2;
    ans += vp.back().second/2;
  }else{
    ans += (ll)vp.front().second/2*k;
    ans += (ll)vp.back().second/2*k;
  }
  cout << ans << endl;
  return 0;
}