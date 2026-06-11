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
  vector<vector<int>> a(3, vector<int>(3));
  rep(i, 3)rep(j, 3) cin >> a.at(i).at(j);
  vector<vector<bool>> chk(3, vector<bool>(3, false));
  int n;
  cin >> n;
  rep(i, n){
    int in;
    cin >> in;
    rep(j, 3)rep(k, 3) if(a.at(j).at(k) == in) chk.at(j).at(k) = true;
  }
  bool f = false;
  rep(i, 3) if(chk.at(i).at(0) == true && chk.at(i).at(1) == true && chk.at(i).at(2) == true) f = true;
  rep(i, 3) if(chk.at(0).at(i) == true && chk.at(1).at(i) == true && chk.at(2).at(i) == true) f = true;
  if(chk.at(0).at(0) == true && chk.at(1).at(1) == true && chk.at(2).at(2) == true) f = true;
  if(chk.at(0).at(2) == true && chk.at(1).at(1) == true && chk.at(0).at(2) == true) f = true;
  if(f == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}