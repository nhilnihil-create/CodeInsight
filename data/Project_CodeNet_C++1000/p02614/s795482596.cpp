//list index out of rangeエラー表示用
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep1(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main(){
  int h, w, k;
  cin >> h >> w >> k;
  vector<vector<char>> C(h, vector<char>(w));
  vector<vector<char>> C_copy(h, vector<char>(w));

  rep1(i, h){
    rep1(j, w){
      cin >> C[i][j];
    }
  }

  int ans = 0;

 

  for (int bit1 = 0; bit1 < (1<<h); ++bit1) {
    for (int bit2 = 0; bit2 < (1<<w); ++bit2) {
      //bit全探索の度に初期化
      rep1(i, h){
        copy(C[i].begin(), C[i].end(), C_copy[i].begin());
      }

      //横行を赤塗り
      for (int i = 0; i < h; i++) {
        if (bit1 & (1<<i)) { // 列挙に i が含まれるか
          rep1(k, w){
            C_copy[i][k] = ' ';
          }
        }
      }

      //縦列を赤塗り
      for (int j = 0; j < w; j++) {          
        if (bit2 & (1<<j)) { // 列挙に j が含まれるか
          rep1(l, h){
            C_copy[l][j] = ' ';
          }
        }
      }

      int tem = 0;
      //countチェック
      rep1(i, h){
        rep1(j, w){
          if(C_copy[i][j] == '#') tem += 1;
        }
      }
      if(tem == k) ans += 1;
    }

  }
  cout << ans;

}

