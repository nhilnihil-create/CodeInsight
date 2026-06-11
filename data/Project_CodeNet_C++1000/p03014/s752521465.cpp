#include <bits/stdc++.h>
using namespace std;
 
int main() {
int H,W;
  cin >> H >> W;
  vector<string> S(H);
  for(int a = 0;a < H;a++){
    cin >> S[a];
  }
  int k = 0;
  int result = 0;
  vector<vector<int>> U(H,vector<int>(W,0));
  vector<vector<int>> D(H,vector<int>(W,0));
  vector<vector<int>> L(H,vector<int>(W,0));
  vector<vector<int>> R(H,vector<int>(W,0));
  //左
  for(int a = 0;a < H;a++){
    for(int b = 0;b < W;b++){
      if(S[a][b] == '#')L[a][b] = -1;
      if(b != 0&&S[a][b] == '.'){
       L[a][b] = L[a][b-1] + 1; 
      }
      
    }
  }
  //右
  for(int a = 0;a < H;a++){
    for(int b = W-1;b >= 0;b--){
      if(S[a][b] == '#')R[a][b] = -1;
      if(b != W-1&&S[a][b] == '.'){
       R[a][b] = R[a][b+1] + 1; 
      }
      
    }
  }
  //上
  for(int a = 0;a < W;a++){
    for(int b = 0;b < H;b++){
      if(S[b][a] == '#')U[b][a] = -1;
      if(b != 0&&S[b][a] == '.'){
       U[b][a] = U[b-1][a] + 1; 
      }
      
    }
  }
  //下
  for(int a = 0;a < W;a++){
    for(int b = H-1;b >= 0;b--){
      if(S[b][a] == '#')D[b][a] = -1;
      if(b != H-1&&S[b][a] == '.'){
       D[b][a] += D[b+1][a] + 1; 
      }
      
    }
  }
  
  for(int a = 0;a < H;a++){
    for(int b = 0;b < W;b++){
      if(S[a][b] == '.'){
      result = max(result,1 + L[a][b] + R[a][b] + D[a][b] + U[a][b]);
      }
    }
  }
  cout << result << endl;
}
