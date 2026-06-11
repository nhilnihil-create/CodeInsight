#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
#define ALL(x) begin(x),end(x)
#define ll long long
#define ld long double
     
int main(){
  //入力
  vector<vector<ll>> a(3,vector<ll>(3));
  rep(i,3)rep(j,3) cin >> a.at(i).at(j);
  ll n; cin >> n;
  vector<ll> b(n); rep(i,n) cin >> b[i];
  sort(ALL(b));
  
  //ビンゴ判定
  bool bingo = false;
  //横方向
  rep(i,3){
    if(find(ALL(b),a.at(i).at(0)) != b.end()
       &&find(ALL(b),a.at(i).at(1)) != b.end()
       &&find(ALL(b),a.at(i).at(2)) != b.end()) bingo = true;
  }
  //縦方向
  rep(i,3){
    if(find(ALL(b),a.at(0).at(i)) != b.end()
       &&find(ALL(b),a.at(1).at(i)) != b.end()
       &&find(ALL(b),a.at(2).at(i)) != b.end()) bingo = true;
  }
  //左上to右下
  if(find(ALL(b),a.at(0).at(0)) != b.end()
       &&find(ALL(b),a.at(1).at(1)) != b.end()
       &&find(ALL(b),a.at(2).at(2)) != b.end()) bingo = true;
  
  //左下to右上
  if(find(ALL(b),a.at(2).at(0)) != b.end()
       &&find(ALL(b),a.at(1).at(1)) != b.end()
       &&find(ALL(b),a.at(0).at(2)) != b.end()) bingo = true;
  
  //出力
  if(bingo) cout << "Yes" << endl;
  else cout << "No" << endl;
}