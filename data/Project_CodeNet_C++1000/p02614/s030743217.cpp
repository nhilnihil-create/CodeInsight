#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int h, w, k;
  int count = 0;
  cin >> h >> w >> k;
  
  char mat[h][w];
  
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      cin >> mat[i][j];  
    }
  }
  
  for(int x = 0; x < (1<<h); x++){
    for(int y = 0; y < (1<<w); y++){
      int black = 0;
      
      for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
          if((mat[i][j]=='#') && ((x>>i)&1) && ((y>>j)&1)) black++;
        }
      }
      
      if(black == k) count++;
    }
  }
  
  cout << count;
  
  return 0;
}