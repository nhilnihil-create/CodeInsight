#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h,w,k;
  cin >> h >> w >> k;
  
  vector<string> c(h);
  for ( int i = 0; i < h; i++) cin >> c[i];
  
  int cnt, ans = 0;
  for ( int a = 0; a < ( 1 << h ); a++){
    for ( int b = 0; b < ( 1 << w ); b++){
      cnt = 0;
      for ( int i = 0; i < h; i++){
        for ( int j = 0; j < w; j++){
          if ( ( a >> i ) & 1 ) continue;
          if ( ( b >> j ) & 1 ) continue;
          if ( c[i][j] == '#' ) cnt++;
        }
      }
      if ( cnt == k ) ans++;
    }
  }
  
  cout << ans << endl;
  return 0;

}