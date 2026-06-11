#include "bits/stdc++.h"
using namespace std;

int main(){
  int H,W,K; cin >> H >> W >> K;
  
  vector<string> c(H);
  for (int i = 0; i < H; i++) cin >> c.at(i);
  //for (int i = 0; i < H; i++) cout << c.at(i) << endl;
  int bt = 0;
  int ans = 0;
  while (bt < (1 << (H+W))){
    vector<bool> H_bool(H,false),W_bool(W,false);
    for (int k = 0; k < H+W; k++) {
	  if ((bt >> k) & 1){
        if (k > H-1) W_bool[k-H] = true;
        else H_bool[k] = true;
      }
    }
    int counter = 0;
    for (int i = 0; i < H; i++){
      for (int j = 0; j < W; j++){
        if (c[i][j] == '#' && H_bool[i] == false && W_bool[j] == false) counter++;
      }
    }
    if (counter == K) ans++;
    bt++;
  }
  cout << ans << endl;
}