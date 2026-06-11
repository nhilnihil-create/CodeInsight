/* Author : arman_ferdous 
 * Date   : 10 May 2020 10:09:33
 * TAG    : Noob Problem 
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;

const int N = 110;
int n, m;
int a[N][N]; char s[N];

int dist[N][N];
deque<pair<int,int>> q;

int dx[] = {1, 0};
int dy[] = {0, 1};

int main() { 
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf(" %s", s + 1);
    for(int j = 1; j <= m; j++) {
      a[i][j] = (s[j] == '.' ? 0 : 1);
    }
  }
  for(int i = 0; i <= n + 1; i++) a[i][0] = a[i][m + 1] = 1; 
  for(int j = 0; j <= m + 1; j++) a[0][j] = a[n + 1][j] = 1;
  a[0][1] = 0; a[n][m + 1] = 0;

  memset(dist, -1, sizeof dist);
  q.push_front({0, 1});
  dist[0][1] = 0;
  while(!q.empty()) {
    int x = q.front().first, y = q.front().second;
    q.pop_front();
    for(int k = 0; k < 2; k++) {
      int tx = x + dx[k], ty = y + dy[k];
      if(min(tx, ty) <= 0 || tx > n || ty > m) continue;

      if(a[x][y] == a[tx][ty] || (a[x][y] == 1 && a[tx][ty] == 0)) {
        if(dist[tx][ty] != -1 && dist[tx][ty] <= dist[x][y]) continue;
        dist[tx][ty] = dist[x][y];
        q.push_front({tx, ty});
      } else {
        if(dist[tx][ty] != -1 && dist[tx][ty] <= dist[x][y]) continue;
        dist[tx][ty] = dist[x][y] + 1;
        q.push_back({tx, ty});
      }
    }
  }
  printf("%d\n", dist[n][m]);
  return 0;
}
