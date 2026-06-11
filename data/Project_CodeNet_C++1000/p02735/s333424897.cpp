#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));
  rep(i,h)rep(j,w) cin >> grid.at(i).at(j);

  vector<vector<int>> dp(h, vector<int>(w,300));
  if(grid.at(0).at(0)=='.') dp.at(0).at(0) = 0;
  else  dp.at(0).at(0) = 1;

  rep(i,h){
    rep(j,w){
      if(j+1<w){
        if(grid.at(i).at(j+1)==grid.at(i).at(j)) dp.at(i).at(j+1) = min(dp.at(i).at(j), dp.at(i).at(j+1));
        else dp.at(i).at(j+1) = min(dp.at(i).at(j)+1, dp.at(i).at(j+1));
      }

      if(i+1<h){
        if(grid.at(i+1).at(j)==grid.at(i).at(j)) dp.at(i+1).at(j) = min(dp.at(i).at(j), dp.at(i+1).at(j));
        else dp.at(i+1).at(j) = min(dp.at(i).at(j)+1, dp.at(i+1).at(j));
      }
    }
  }
  // rep(i,h){
  //   rep(j,w){
  //     cout << dp.at(i).at(j);
  //   }cout << endl;
  // }
  int c = dp.at(h-1).at(w-1);
  cout << (c+1)/2;
}