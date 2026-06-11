#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {1, 1, 1, 0, 0, -1, -1, -1};

int c[50][50];
int w, h;

void dfs(int x, int y)
{
  if (x < 0 || y < 0 || w == x || h == y) return;
  if (c[x][y] == 0) return;
  c[x][y] = 0;
  for (int i = 0; i < 8; i++){
    dfs(x + dx[i], y + dy[i]);
  }
}

int main()
{
  while (cin >> w >> h, w){
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        cin >> c[j][i];
      }
    }

    int cnt = 0;
    for (int i = 0; i < h; i++){
      for (int j = 0; j < w; j++){
        if (c[j][i] == 1){
          cnt++;
          dfs(j, i);
        }
      }
    }
    cout << cnt << endl;
  }
}