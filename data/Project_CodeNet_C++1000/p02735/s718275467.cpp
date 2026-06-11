#include <bits/stdc++.h>
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  for(int i = 0; i < h; i++) cin >> grid.at(i);
  
  vector<vector<int>> dp(h, vector<int> (w, 100000));
  if(grid.at(0).at(0) == '#') dp.at(0).at(0) = 1;
  else dp.at(0).at(0) = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int score = dp.at(i).at(j), down, right;
      char c = grid.at(i).at(j);
      if(i+1 < h) down = dp.at(i+1).at(j);
      if(j+1 < w) right = dp.at(i).at(j+1);
      if(c == '#'){
        if(i+1 < h) dp.at(i+1).at(j) = min(down, score);
        if(j+1 < w) dp.at(i).at(j+1) = min(right, score);
        continue;
      }
      if(i+1 < h){
        if(grid.at(i+1).at(j) == '#') dp.at(i+1).at(j) = min(down,score + 1);
        else dp.at(i+1).at(j) = min(down, score);
      }
      if(j+1 < w){
        if(grid.at(i).at(j+1) == '#') dp.at(i).at(j+1) = min(right, score + 1);
        else dp.at(i).at(j+1) = min(right, score);
      }
    }
  }
  
  cout << dp.at(h-1).at(w-1) << endl;
}