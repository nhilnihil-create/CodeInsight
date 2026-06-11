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
  int n;
  cin >> n;
  vector<pair<int, int>> vp(n);
  rep(i, n){
    int x, y;
    cin >> x >> y;
    vp.at(i) = make_pair(x, y);
  }
  sort(vp.begin(), vp.end());
  map<pair<int, int>, int> mp;
  rep(i, n){
    rep2(j, i+1, n){
      pair<int, int> add;
      add.first = vp.at(i).first - vp.at(j).first;
      add.second = vp.at(i).second - vp.at(j).second;
      mp[add]++;
    }
  }
  int mx = 0;
  for(auto p : mp){
    mx = max(mx, p.second);
  }
  cout << n - mx << endl;
  return 0;
}