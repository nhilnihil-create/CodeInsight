#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
  int H, W, K;
  cin >> H >> W >> K;
  int black = 0;
  vector<vector<char>> c(H+1, vector<char>(W+1));
  vector<int> rowb(H+1), colb(W+1);
  for(int i=1; i<=H; i++){
    for(int j=1; j<=W; j++){
      cin >> c.at(i).at(j);
      if(c.at(i).at(j)=='#'){
        black++;
        rowb.at(i)++;
        colb.at(j)++;
      }
    }
  }
  int ans = 0;
  for(int tmp=0; tmp<(1<<12); tmp++){
    bitset<12> s(tmp);
    int eraceb = 0;
    for(int i=0; i<H; i++){
      if(s.test(i)){
        eraceb += rowb.at(i+1);
      }
    }
    for(int j=6; j<6+W; j++){
      if(s.test(j)){
        eraceb += colb.at(j-5);
      }
    }
    for(int i=0; i<H; i++){
      for(int j=6; j<6+W; j++){
        if(!s.test(i)||!s.test(j)) continue;
        if(c.at(i+1).at(j-5)=='#') eraceb--;
      }
    }
    if(black-eraceb==K) ans++;
  }
  int m = 1;
  for(int i=0; i<12-H-W; i++){
    m *= 2;
  }
  cout << ans/m;
  return 0;
}