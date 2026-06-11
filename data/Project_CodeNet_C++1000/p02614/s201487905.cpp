#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W,K;
  cin >> H >> W >> K;
  vector<vector<char>> C(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin >> C.at(i).at(j);
    }
  }
  int count=0;
  for(int bith=0;bith<(1<<H);bith++){
    for(int bitw=0;bitw<(1<<W);bitw++){
      int kuro=0;
      for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
          if(bith &(1<<i)){
            continue;
          }
          if(bitw &(1<<j)){
            continue;
          }
          if(C.at(i).at(j)=='#'){
            kuro++;
          }
        }
      }
      if(kuro==K){
        count++;
      }
    }
  }
  cout << count << endl;
}
      