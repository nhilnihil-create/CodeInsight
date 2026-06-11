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
  string s, t;
  cin >> s >> t;
  map<char, vector<int>> mp;
  rep(i, s.size()){
    mp[s.at(i)].push_back(i);
  }
  ll ans = 0, index = -1;
  for(char c : t){
    if(mp[c].size() == 0){
      cout << -1 << endl;
      return 0;
    }
    auto itr = upper_bound(ALL(mp[c]), index);
    if(itr == mp[c].end()){
      ans += s.size()-index-1;
      index = -1;
      itr = mp[c].begin();
    }
    ans += (*itr-index);
    index = *itr;
    // cerr << ans << endl;
  }
  cout << ans << endl;
  return 0;
}