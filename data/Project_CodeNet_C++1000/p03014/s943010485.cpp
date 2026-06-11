#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for(int i = 0; i < h; i++) cin >> s.at(i);
  
  int l[2010][2010], r[2010][2010], u[2010][2010], d[2010][2010];
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      if(s.at(i).at(j) == '.'){
        if(j == 0) l[i][j] = 1;
        else l[i][j] = l[i][j-1] + 1;
        if(i == 0) u[i][j] = 1;
        else u[i][j] = u[i-1][j] + 1;
      }
      int x = w - 1 - j, y = h - 1 - i;
      if(s.at(y).at(x) == '.'){
        if(y == h-1) d[y][x] = 1;
        else d[y][x] = d[y+1][x] + 1;
        if(x == w-1) r[y][x] = 1;
        else r[y][x] = r[y][x+1] + 1;
      }
    }
  }
  
  int ans = 0;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      int now = l[i][j] + r[i][j] + u[i][j] + d[i][j] - 3;
      ans = max(ans, now);
    }
  }
  
  cout << ans << endl;
}