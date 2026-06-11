#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H,W;
  cin >> H >> W;

  vector<string>S(H);
  for (int i = 0; i < H; i++) {
      cin >> S.at(i);
  }
  
  int count = 0;
  vector<vector<int>> yoko(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (S.at(i).at(j) == '.'){
        count++;
      }
      
      if (S.at(i).at(j) == '#'){
        yoko.at(i).at(j) = 0;
          for (int k = 0; k < count; k++) {
            yoko.at(i).at(j-k-1) = count;
          }
        count = 0;
      }
      else if (S.at(i).at(j) == '.' && j == W-1){
        for (int k = 0; k < count; k++) {
          yoko.at(i).at(j-k) = count;
        }
        count = 0;
      }
    }
  }
  
  count = 0;
  vector<vector<int>> tate(H, vector<int>(W));
  for (int j = 0; j < W; j++) {
    for (int i = 0; i < H; i++) {
      if (S.at(i).at(j) == '.'){
        count++;
      }
      
      if (S.at(i).at(j) == '#'){
        tate.at(i).at(j) = 0;
          for (int k = 0; k < count; k++) {
            tate.at(i-k-1).at(j) = count;
          }
        count = 0;
      }
      else if (S.at(i).at(j) == '.' && i == H-1){
        for (int k = 0; k < count; k++) {
          tate.at(i-k).at(j) = count;
        }
        count = 0;
      }
    }
  }
  
  int j = 0;
  int k = 0;
  vector<int>A(H*W);
  for (int i = 0; i < H*W; i++) {
    A.at(i) = tate.at(j).at(k) + yoko.at(j).at(k);
    if (k == W-1){
      k = 0;
      j++;
    }
    else {
      k++;
    }
  }
  sort(A.begin(), A.end());
  cout << A.at(H*W-1)-1 << endl;
}
     