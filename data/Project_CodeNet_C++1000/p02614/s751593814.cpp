using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

int main(){
  int H, W, K;
  cin >> H >> W >> K;
  
  vector<string> grid;
  string row;
  for (int i = 0; i < H; i++){
    cin >> row;
    grid.push_back(row);
  }
  
  int score = 0;
  bool cond1, cond2, cond3;
  
  for (int h = 0; h < (1 << H); h++){
    for (int w = 0; w < (1 << W); w++){
      int black = 0;
      for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
          cond1 = ((h >> i) & 1) == 1;
          cond2 = ((w >> j) & 1) == 1;
          cond3 = grid[i][j] == '#';
          
          if ((cond1 && cond2) && cond3) black += 1;
        }
      }
      if (black == K) score += 1;
    }
  }
  
  cout << score;

  return 0;
}