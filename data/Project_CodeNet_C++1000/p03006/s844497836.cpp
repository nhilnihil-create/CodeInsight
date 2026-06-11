#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(n) begin(n), end(n)
using ll = long long;
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> vp;
  map<pair<int, int>, int> m;
  rep(i, n){
    int x, y;
    cin >> x >> y;
    vp.push_back(make_pair(x, y));
  }
  rep(i, n){
    rep(j, n){
      if(i == j) continue;
      m[make_pair(vp.at(i).first - vp.at(j).first, vp.at(i).second - vp.at(j).second)]++;
    }
  }
  int mx = 0;
  for(auto p : m){
    mx = max(mx, p.second);
  }
  int ans = n - mx;
  cout << ans << endl;
  return 0;
}