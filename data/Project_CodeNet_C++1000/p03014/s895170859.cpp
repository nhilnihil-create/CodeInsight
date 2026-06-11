#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";

int main(){
  ll h,w; cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w,'.'));
  // あるシャープより左にあるドットの累積をsrとする。
  // sr[i][n]=i行目の左からn番目のシャープより左
  // sr[i][0]はゼロとする
  vector<vector<ll>> sr(h);
  // あるシャープより上にあるドットの累積をsc
  // sc[j][m]=j列目の上からm番目のシャープより上
  // sc[j][0]はゼロとする
  vector<vector<ll>> sc(w);
  rep(i,h){
    ll ruiseki=0;
    sr[i].push_back(0);
    rep(j,w){
      cin >> s[i][j];
      if(s[i][j]=='#'){
        sr[i].push_back(ruiseki);
      }else{
        ruiseki++;
      }
    }
    sr[i].push_back(ruiseki);
  }
  rep(j,w){
    ll ruiseki=0;
    sc[j].push_back(0);
    rep(i,h){
      char cur = s[i][j];
      if(s[i][j]=='#'){
        sc[j].push_back(ruiseki);
      }else{
        ruiseki++;
      }      
    }
    sc[j].push_back(ruiseki);
  }
  vector<vector<ll>> ans(h+1,vector<ll>(w+1,0));
  rep(i,h){
    ll sharpcnt = 0;
    rep(j,w){
      if(s[i][j]=='#'){
        sharpcnt++;
      }else{
        ans[i][j]+=sr[i][sharpcnt+1]-sr[i][sharpcnt];
      }
    }
  }
  rep(j,w){
    ll sharpcnt = 0;
    rep(i,h){
      if(s[i][j]=='#'){
        sharpcnt++;
      }else{
        ans[i][j]+=sc[j][sharpcnt+1]-sc[j][sharpcnt];
      }      
    }
  }
  ll dest=0;
  rep(i,h)rep(j,w){
    dest = max(dest, ans[i][j]-1);
  }
  cout << dest << endl;
  return 0;
}


