#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int h, w; cin >> h >> w;
  int cnt[h][w];
  char s[h][w];
  P mv[] = {make_pair(0, 1), make_pair(1, 0)};
  rep(i, h) rep(j, w) cin >> s[i][j];
  int INF = 1e9;
  rep(i, h) rep(j, w) cnt[i][j] = INF;

  queue<P> q;
  q.push(make_pair(0, 0));
  if(s[0][0] == '.') cnt[0][0] = 0;
  else cnt[0][0] = 1;

  while(!q.empty()){
    P now = q.front(); q.pop();
    rep(i, 2){
      int nx = now.first + mv[i].first, ny = now.second + mv[i].second;
      if(nx >= h || ny >= w) continue;
      if(cnt[nx][ny] == INF) q.push(make_pair(nx, ny));

      int c = cnt[now.first][now.second];
      if(s[nx][ny] == '#' && s[now.first][now.second] == '.') c++;


      cnt[nx][ny] = min(cnt[nx][ny], c);

    }
  }

  /*rep(i, h){
    rep(j, w) cout << cnt[i][j] << " "; cout << endl;
  }*/
  cout << cnt[h - 1][w - 1] << endl;
  return 0;
}
