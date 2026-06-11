#include <iostream>
using namespace std;

int w, h;
int field[60][60];

void dfs(int x, int y) {
  field[y][x] = 0;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      int tx = x+j, ty = y+i;
      if(0 <= tx && tx < w && 0 <= ty && ty < h && field[ty][tx] == 1) dfs(tx, ty);
    }
  }
}

int main() {
  while(cin >> w >> h, w+h) {
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	cin >>field[i][j];
      }
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
	if(field[i][j]) {
	  ans++;
	  dfs(j, i);
	}
      }
    }
    cout << ans << endl;
  }
}