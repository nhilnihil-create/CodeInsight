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
  string s, t;
  cin >> s >> t;
  vector<bool> chk(26, false);
  vector<vector<int>> index(26, vector<int>());
  rep(i, s.size()){
    int now = s.at(i) - 'a';
    chk.at(now) = true;
    index.at(now).push_back(i);
  }
  rep(i, t.size()){
    int now = t.at(i) - 'a';
    if(chk.at(now) != true){
      cout << -1 << endl;
      return 0;
    }
  }

  int ni = s.size();
  ll ans = 0;
  rep(i, t.size()){
    int now = t.at(i) - 'a';
    auto itr = upper_bound(index.at(now).begin(), index.at(now).end(), ni);
    if(itr == index.at(now).end()){
      ans += index.at(now).front() + (s.size()-ni);
      ni = index.at(now).front();
    }else{
      ans += *itr - ni;
      ni = *itr;
    }
  }
  ans++;
  cout << ans << endl;
  return 0;
}