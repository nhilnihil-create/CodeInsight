#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int INF = 1000000000;
#define REP(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define rep(i,n) REP(i, 0, n)
typedef pair<int, int> pint;
const int dx[4] = {0, 1, -1, 0}, dy[4] = {1, 0, 0, -1};
int W, H;
int solve(vector<string>& fld, int sx, int sy){
    queue<pint> que;
    int res = 0;
    que.push(pint(sx, sy));
    while(!que.empty()){
        pint now = que.front(); que.pop();
        if(fld[now.second][now.first] == '.'){
            res++;
            fld[now.second][now.first] = '#';
        }else
          continue;
        rep(i, 4){
            int nx = now.first + dx[i], ny = now.second + dy[i];
            if(nx < 0 || ny < 0 || W <= nx || H <= ny)
              continue;
            que.push(pint(nx, ny));
        }
    }
    return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> W >> H && W){
        vector<string> fld(H);
        rep(i, H) cin >> fld[i];
        int sx, sy;
        rep(i, H) rep(j, W)
          if(fld[i][j] == '@'){
              sx = j;
              sy = i;
              fld[i][j] = '.';
              break;
          }
        cout << solve(fld, sx, sy) << endl;
    }
}