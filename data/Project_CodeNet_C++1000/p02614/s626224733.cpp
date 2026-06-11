#include <bits/stdc++.h>
using namespace std; 

int main(){
  int H,W,K,ans=0;
  cin >> H >> W >> K;
  vector<vector<char>> C(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> C.at(i).at(j);
    }
  }
  for(int bitH=0;bitH<(1<<H);bitH++){
    for(int bitW=0;bitW<(1<<W);bitW++){
      int count=0;
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(bitH & (1<<i)){
            continue;
          }
          if(bitW & (1<<j)){
            continue;
          }
          if(C.at(i).at(j)=='#'){
            count++;
          }
        }
      }
      if(count==K){
        ans++;
      }
    }
  }
  cout << ans << endl;
}