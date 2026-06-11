#include <iostream>
using namespace std;

bool field[100][100];

int w, h;

int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, -1, 0, 1, -1, 1, -1, 1};

void bfs(int x, int y) {
  field[y][x] = false;
  for(int i = 0; i < 8; i++) {
    int tx = x+dx[i], ty = y+dy[i];

    if(0 <= tx && tx < w && 0 <= ty && ty < h && field[ty][tx]) {
      bfs(tx, ty);
    }
  }
}

int main() {
  while(cin >> w >> h, w+h) {
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        cin >> field[i][j];
      }
    }

    int ans = 0;
    for(int i = 0; i < h; i++) {
      for(int j = 0; j < w; j++) {
        if(field[i][j]) {
          ans++;
          bfs(j, i);
          /*for(int k = 0; k < h; k++) {
            for(int l = 0; l < w; l++) {
              cout<< field[k][l] << ' ';
            }
            cout<< endl;
          }
          cout << endl;*/
        }
      }
    }
    cout << ans << endl;
  }
}