#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W, K, ans = 0;
  cin >> H >> W >> K;
  
  vector<char> board(H * W);
  
  for (int i = 0; i < H; i++){
    string C;
    cin >> C;
    
    for (int j = 0; j < W; j++){
      
      board.at(i * W + j) = C.at(j);
        
    }
  }
  
  for (int bit = 0; bit < (1 << H); bit++){
    for (int bit2 = 0; bit2 < (1 << W); bit2++){
      int num = 0;
      for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++){
          //cout << bit2 << endl;
          if (!(bit & (1 << i)) && !(bit2 & (1 << j)) && board.at(i * W + j) == '#'){
            num++;
          }
        }
      }
      
      if (num == K){
        ans++;
      }
      
    }
  }
  
  cout << ans << endl;
}