#include <iostream>
#include <vector>
using namespace std;

int main() {
  int H, W, K;
  cin >> H >> W >> K;
  char d[H][W];
  string s;
  for (int i=0; i<H; i++){
    cin >> s;
    for (int j=0; j<W; j++){
      d[i][j]=s.at(j);
    }
  }
  int ans = 0;
  for (int bitt = 0; bitt < (1<<H); bitt++) {
    for (int bity = 0; bity < (1<<W); bity++) {
      int count=0;
      for (int i = 0; i < H; i++) {
        for (int j=0; j < W; j++) {
          if ((bitt & (1<<i)) && (bity & (1<<j)) && (d[i][j]=='#')) {
              count++;
          }
        }
      }
      if (count==K)
        ans++;
    }
  }
  cout << ans << endl;
}
