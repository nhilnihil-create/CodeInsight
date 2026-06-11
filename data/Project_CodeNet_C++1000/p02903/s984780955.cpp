#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w,a,b;
  cin >> h >> w >> a >> b;
  vector<vector<int>>data(h,vector<int>(w,0));
  for(int i = 0;i < h;i++){
    for(int j = 0;j < w;j++){
      if(i<b^j<a) data[i][j] = 1;
      cout << data[i][j];
    }
    cout << "" << endl;
  }
}
