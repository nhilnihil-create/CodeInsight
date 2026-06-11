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

int fc(const vector<int> &v, int i, int j){
  int res = v.size() - (lower_bound(ALL(v), j) - v.begin());
  int t = j - i;
  t += j;
  auto itr = lower_bound(ALL(v), t);
  if(itr != v.end() && *itr == t)res--;
  return res;
}

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> v(3, vector<int>());
  rep(i, s.size()){
    if(s.at(i) == 'R') s.at(i) = 0;
    if(s.at(i) == 'G') s.at(i) = 1;
    if(s.at(i) == 'B') s.at(i) = 2;
  }
  ll ans = 0;
  rep(i, n) v.at(s.at(i)).push_back(i);
  rep(i, n)rep2(j, i+1, n){
    if(s.at(i) == s.at(j)) continue;
    rep(l, 3){
      if(s.at(i) != l && s.at(j) != l) ans += fc(v.at(l), i, j);
    }
  }
  cout << ans << endl;
  return 0;
}