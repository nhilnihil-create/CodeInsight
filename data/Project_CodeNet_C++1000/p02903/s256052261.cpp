#include <bits/stdc++.h>                                                                                                                                                                                  
using namespace std;
 
int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  bool yes = true;
  if(a > w / 2) yes = false;
  if(b > a / 2) yes = false;
  vector<vector<int>> ans(h, vector<int>(w));
  for(int i=0;i<h;i++) {
    if(i < b) {
      for(int j=0;j<w;j++) {
        if(j < a) ans[i][j] = 0;
        else ans[i][j] = 1;
      }   
    }   
    else {
      for(int j=0;j<w;j++) {
        if(j < a) ans[i][j] = 1;
        else ans[i][j] = 0;
      }   
    }   
  }
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      cout << ans[i][j];
    }   
    cout << endl;
  }
  return 0;
}