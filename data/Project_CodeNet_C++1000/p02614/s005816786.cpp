#include <iostream>
#include <string>

using namespace std;

int main(){
  int H, W, K;
  cin >> H >> W >> K;
  string S[6];
  for(int i=0; i<H; i++) {
    cin >> S[i];
  }

  int ans = 0;

  // Try 2^H times
  for (int a = 0; a < (1 << H); a++) {

    // Try 2^W times
    for (int b = 0; b < (1 << W); b++) {
      int cnt = 0;

      for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
          if ( (((a >> i) & 1) == 0 ) && ((( b >> j ) & 1) == 0) && S[i][j] == '#' ) {
            cnt++;
          }
        }
      }

      if (cnt == K) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}