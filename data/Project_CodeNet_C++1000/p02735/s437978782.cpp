#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin >> H >> W;
  
  vector<string> S(H);
  for (int i = 0; i < H; i++){
    cin >> S.at(i);
  }
  
  vector<vector<int>> dp(120, vector<int>(120, 0));
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (i == 0 && j == 0){
        if (S.at(0).at(0) == '#'){
          dp.at(0).at(0) = 1;
        }
        else{
          dp.at(0).at(0) = 0;
        }
      }
      else if (i == 0){
        if (S.at(0).at(j) == '#' && S.at(0).at(j - 1) == '.'){
          dp.at(0).at(j) = dp.at(0).at(j - 1) + 1;
        }
        else{
          dp.at(0).at(j) = dp.at(0).at(j - 1);
        }
      }
      else if (j == 0){
        if (S.at(i).at(0) == '#' && S.at(i - 1).at(0) == '.'){
          dp.at(i).at(0) = dp.at(i - 1).at(0) + 1;
        }
        else{
          dp.at(i).at(0) = dp.at(i - 1).at(0);
        }
      }
      else{
        int down = 0, right = 0;
        if (S.at(i).at(j) == '#' && S.at(i).at(j - 1) == '.'){
          right = 1;
        }
        
        if (S.at(i).at(j) == '#' && S.at(i - 1).at(j) == '.'){
          down = 1;
        }
            
        dp.at(i).at(j) = min(dp.at(i).at(j - 1) + right, dp.at(i - 1).at(j) + down);
      }
    }
  }
            
  /*for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      cout << dp.at(i).at(j) << ' ';
    }
    cout << endl;
  }*/
  cout << dp.at(H - 1).at(W - 1) << endl;
}