#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

typedef pair<int, int> Pi;
#define fi first
#define se second

int mx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int my[] = {0, 1, 1, 1, 0, -1, -1, -1};
int W, H;
int mas[55][55];

void bfs(int sy, int sx) {
  
  queue < Pi > que;
  que.push(Pi(sy, sx));

  while(!que.empty()) {
    Pi d = que.front(); que.pop();
    int y = d.fi, x = d.se;
    Rep(i, 8) {
      int ny = y + my[i], nx = x + mx[i];
      if(ny < 0 || nx < 0 || ny >= H || nx >= W || !mas[ny][nx]) continue;
      mas[ny][nx] = 0; bfs(ny, nx);
    }
  }
}

signed main()
{  
  while(cin >> W >> H, W || H) {
    int ans = 0;
    Rep(i, H) Rep(j, W) cin >> mas[i][j];

    Rep(i, H) Rep(j, W) {
      if(mas[i][j]) {
	mas[i][j] = 0, ans++;
	bfs(i, j);
      }
    }

    cout << ans << endl;
  }
}