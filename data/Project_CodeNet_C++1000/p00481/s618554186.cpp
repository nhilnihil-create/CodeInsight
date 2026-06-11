#include <stdio.h>
#include <queue>
#include <utility>

int main(void) {
  int i, j, k, h, w, n, inf = 10e9, dy[4] = {1, 0, 0, -1}, dx[4] = {0, 1, -1, 0};
  scanf("%d%d%d", &h, &w, &n);
  char m[h][w + 10];
  int ans = 0, bfs[h][w], cy[n + 1], cx[n + 1];
  for(i = 0; i < h; ++i) {
    scanf("%s", m[i]);
    for(j = 0; j < w; ++j) {
      if(m[i][j] > '0' && m[i][j] <= '9') cy[m[i][j] - '0'] = i, cx[m[i][j] - '0'] = j;
      if(m[i][j] == 'S') cy[0] = i, cx[0] = j;
    }
  }
  for(k = 0; k < n; ++k) {
    for(i = 0; i < h; ++i) for(j = 0; j < w; ++j) bfs[i][j] = inf;
    bfs[cy[k]][cx[k]] = ans;
    std::queue< std::pair<int, int> > q;
    q.push(std::make_pair(cy[k], cx[k]));
    while( 1 ) {
      int s = 0;
      std::queue< std::pair<int, int> > qt;
      while(!q.empty()) {
        int nowy = q.front().first, nowx = q.front().second;
        q.pop();
        for(i = 0; i < 4; ++i) if(nowy + dy[i] >= 0 && nowy + dy[i] < h && nowx + dx[i] >= 0 && nowx + dx[i] < w && m[nowy + dy[i]][nowx + dx[i]] != 'X' && bfs[nowy + dy[i]][nowx + dx[i]] > bfs[nowy][nowx] + 1) {
          bfs[nowy + dy[i]][nowx + dx[i]] = bfs[nowy][nowx] + 1;
          if(nowy + dy[i] == cy[k + 1] && nowx + dx[i] == cx[k + 1]) {
            s = 1;
            break;
          }
          qt.push(std::make_pair(nowy + dy[i], nowx + dx[i]));
        }
        if(s) break;
        while(!qt.empty()) q.push(qt.front()), qt.pop();
      }
      if(s) {
       ans = bfs[cy[k + 1]][cx[k + 1]];
       break;
      }
    }
  }
  printf("%lld\n", ans);
  return 0; 
} 
