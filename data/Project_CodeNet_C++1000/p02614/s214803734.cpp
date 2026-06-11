#include <bits/stdc++.h>
using namespace std;

int main () {
  int H,W,K;
  cin >> H >> W >> K;
  vector<vector<char>> data(H, vector<char>(W));
 
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int sum = 0;

  // すべての選び方を試して、総和がKになるものがあるかを調べる
  for (int tmp = 0; tmp < (1 << 12); tmp++) {
    bitset<12> s(tmp);  // 最大20個なので20ビットのビット列として扱う
    
    if (H + W < 12 && s.test(H+W)) {
      break;
    }

    // ビット列の1のビットに対応する整数を選んだとみなして総和を求める
    int count = 0;
    
    vector<vector<char>> data2(H, vector<char>(W));
 
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        data2.at(i).at(j) = data.at(i).at(j);
      }
    }
    
    for (int i = 0; i < H+W; i++) {
      if (s.test(i)) {
        if (i < H){
          for (int j = 0; j < W; j++) {
            data2.at(i).at(j) = '.';
          }
        }
        else {
          for (int j = 0; j < H; j++) {
            data2.at(j).at(i-H) = '.';
          }
        }
      }    
    }
    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (data2.at(i).at(j) == '#'){
          count++;
        }
      }
    }
    if (count == K) {
      sum++;
    }
  }
  
  cout << sum << endl;
}

  