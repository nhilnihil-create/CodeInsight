#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr char block= '#';
  int H,W;
  cin >> H >> W;

  vector<string> data(H);
  for(int i=0; i<H; i++){
    cin >> data.at(i);
  }

  vector<vector<int>> dp(H, vector<int>(W));
  dp.at(0).at(0)= (data.at(0).at(0)==block) ? 1
                                            : 0;
  for(int j=1; j<W; j++){
    dp.at(0).at(j)= (data.at(0).at(j)==block && data.at(0).at(j-1) != block) ? dp.at(0).at(j-1)+ 1
                                                                             : dp.at(0).at(j-1);
  }
  for(int i=1; i<H; i++){
    dp.at(i).at(0)= (data.at(i).at(0)==block && data.at(i-1).at(0) != block) ? dp.at(i-1).at(0)+ 1
                                                                             : dp.at(i-1).at(0);
  }

  for(int i=1; i<H; i++){
    for(int j=1; j<W; j++){
      int diff_x= (data.at(i).at(j)==block && data.at(i-1).at(j) != block) ? 1
                                                                           : 0;

      int diff_y= (data.at(i).at(j)==block && data.at(i).at(j-1) != block) ? 1
                                                                           : 0;

      dp.at(i).at(j)= min(dp.at(i-1).at(j)+ diff_x, dp.at(i).at(j-1)+ diff_y);
    }
  }
  
  cout << dp.back().back() << endl;
}