#include<bits/stdc++.h>
using namespace std;

int main(){
  int H , W , K ;
  cin >> H >> W >> K ;
  vector<vector<char>> c(H, vector<char>(W));
  for(int i = 0; i < H; i++)
    for(int j = 0; j < W; j++)
      cin >> c[i][j];
  int ans = 0;
  for(int Hbit = 0; Hbit < (1<<H); Hbit++){
    for(int Wbit = 0; Wbit < (1<<W); Wbit++){
      int black = 0;
      for(int i = 0; i < H; i++) for(int j = 0; j < W; j++){
        if( !(Hbit & (1<<i) || Wbit & (1<<j)) && c[i][j] == '#') black++;
      }
      if(black == K) ans++;
    }
  } 
  cout << ans;
}
