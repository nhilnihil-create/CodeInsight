#include <bits/stdc++.h>
using namespace std;

void chmax(int&a, int b) {
  if (a < b) a = b;
}

int main() {
  int H, W;
  cin >> H >> W;
  
  char c[2010][2010];
  int column[2010][2010] = {0}, row[2010][2010] = {0};
  
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> c[i][j];
    }
    c[i][W+1] = '#';
  }
  
  for (int j = 1; j <= W; j++){
    c[H+1][j] = '#';
  } 
  
  // column 作成
  for (int i = 1; i <= H; i++) { // 各行に対して
    int ind = 1;
    int count = 0;
    for (int j = 1; j<=W+1; j++) {
       if (c[i][j] =='.') {
         count++;
         continue;
       } else {
         while(ind < j) {
           column[i][ind] = count;
           ind++;
         }
         ind++;
         count = 0;
       }
    }
  } 
  

  // row 作成
  for (int j = 1; j <= W; j++) { // 各列に対して
    
    int ind = 1;
    int count = 0;
    for (int i = 1; i<= H+1; i++) {
       if (c[i][j] =='.') {
         count++;
         continue;
       } else {
         while(ind < i) {
           row[ind][j] = count;
           ind++;
         }
         ind++;
         count = 0;
       }
    }
  } 

    

  
  // それぞれのマスでいくつ照るのかチェック
  int ans = 0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j<= W; j++) {
      if (c[i][j] == '.') {
        chmax(ans, row[i][j] + column[i][j]-1);
      }
    }
  }
  
  cout << ans << endl;
}