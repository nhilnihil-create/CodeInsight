#include <bits/stdc++.h>

using namespace std;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
int h, w, d, dp[105][105];
char a[105][105];
bool path[101][101][101][101];

void BFS(int u, int v) {
    path[u][v][u][v] = 1;
    queue < pair <int, int > > q;
    q.push(make_pair(u, v));
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int dir=0 ; dir<2 ; ++dir) {
        int nextU = xx + dx[dir];
        int nextV = yy + dy[dir];
        if(a[nextU][nextV]=='#' && path[u][v][nextU][nextV] == 0) {
            q.push(make_pair(nextU, nextV));
            path[u][v][nextU][nextV] = 1;
        }
    }
    }

}

int main()
{
    if (fopen(".inp", "r")) freopen(".inp", "r", stdin);
    cin >> h >> w;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) cin >> a[i][j];
    }
    d = 0;

   for(int i=1 ; i<=h ; ++i)
       for(int j=1 ; j<=w ; ++j) {
            BFS(i, j);
       }

    for(int i = 2; i <= h; ++i) dp[i][0] = 1e9;
    for(int j = 2; j <= w; ++j) dp[0][j] = 1e9;
    for(int i = 1; i <= h; ++i) {
        for(int j = 1; j <= w; ++j) {
            if(a[i][j] == '.') {dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]); continue;}
          //  dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
          dp[i][j] = 1e9;
            for(int u = 1; u <= i; ++u) {
                for(int v = 1; v <= j; ++v) {
                    if(path[u][v][i][j]) dp[i][j] = min(dp[i][j], min(dp[u - 1][v], dp[u][v - 1]) + 1);
                }
            }
        }
    }
    cout << dp[h][w];
    return 0;
}
