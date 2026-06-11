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
  int n;
  cin >> n;
  ll k;
  cin >> k;
  vector<int> a(n);
  rep(i, n) cin >> a.at(i);
  rep(i, n) a.at(i)--;
  vector<vector<int>> db(60, vector<int>(n));
  rep(i, n) db.at(0).at(i) = a.at(i);
  rep(i, db.size()-1){
    rep(j, n){
      db.at(i+1).at(j) = db.at(i).at(db.at(i).at(j));
    }
  }
  int ans = 0;
  rep(bit, 60){
    if((k & (1LL << bit)) != 0){
      ans = db.at(bit).at(ans);
    }
  }
  cout << ans+1 << endl;
  return 0;
}