#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> P;

const int MAX_H = 1000;
const int MAX_W = 1000;
const int MAX_N = 9;
const int INF = INT32_MAX;

char maze[MAX_H][MAX_W + 1];

int H, W, N;
int si, sj;
int gi[MAX_N + 1], gj[MAX_N + 1];
int d[MAX_H][MAX_W];

int dx[4] = {0,  1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int bfs(int goalNum)
{
  queue<P> que;
  int cgi = gi[goalNum], cgj = gj[goalNum];

  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++)
      d[i][j] = INF;

  que.push(P(si, sj));
  d[si][sj] = 0;

  while (que.size()) {
    P p = que.front(); que.pop();

    if (p.first == cgi && p.second == cgj) break;

    for (int i = 0; i < 4; i++) {
      int ni = p.first + dx[i], nj = p.second + dy[i];

      if (0 <= ni && ni < H && 0 <= nj && nj < W && maze[ni][nj] != 'X' && d[ni][nj] == INF) {
        que.push(P(ni, nj));
        d[ni][nj] = d[p.first][p.second] + 1;
      }
    }
  }

  return d[cgi][cgj];
}

int solve()
{
  int res = 0;
  for (int i = 1; i <= N; i++) {
    // printf("%d:(%d, %d) => ", i, si, sj);
    res += bfs(i);
    si = gi[i]; sj = gj[i];
    // printf("(%d, %d):%d\n", si, sj, res);
  }
  return res;
}

int main()
{
  scanf("%d %d %d", &H, &W, &N);
  for (int i = 0; i < H; i++) {
    scanf("%s", maze[i]);
    maze[i][W] = 0;

    for (int j = 0; j < W; j++) {
      if ('0' < maze[i][j] && maze[i][j] <= '9') {
        gi[maze[i][j] - '0'] = i;
        gj[maze[i][j] - '0'] = j;
      }
      if (maze[i][j] == 'S') {
        si = i;
        sj = j;
      }
    }
  }

  printf("%d\n", solve());
}

