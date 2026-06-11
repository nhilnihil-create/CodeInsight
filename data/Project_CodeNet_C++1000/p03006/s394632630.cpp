#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define For(i, a, b) for(int i = (a); i < (b); ++i)
#define all(x) (x).begin(),(x).end()
typedef long long lint;

int gcd(int x, int y){
    if (x == 0) return y;
    return gcd(y % x, x);
};

int lcm(int x, int y){
    return x * y / gcd(x, y);
};

int powint(int x, int y){
    int ret = 1;
    for (int i=0; i < y; i++) ret *= x;
    return ret;
};

int powmod(int x, int y, int m){
    if (y == 0) return 1;
    return ((powint(powmod(x, y>>1, m), 2) % m) * powint(x, (y & 1))) % m;
};

int comb(int n, int r, int m){
    if (n < r) return 0;

    if (n-r < r) r = n-r;
    int ret = 1; int d = 1;
    for (int i = n-r+1; i < n+1; i++) ret = (ret * i) % m;
    for (int i = 1; i < r+1; i++) d = (d * i) % m;
    ret *= powmod(d, m-2, m);
    return ret % m;
};

int min_arr(vector<int> x){
    int y = x[0];
    rep(i, x.size()){
        y = min(y, x[i]);
    }
    return y;
};

int mod = 1000000007;
vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
vector<int> dy = {0, -1, 1, 0, 1, -1, 1, -1};

map<char, int> counter(string s){
    map<char, int> count;
    rep(i, s.size()){
        count[s[i]] ++;
    }
    return count;
};

vector<vector<int>> grid_bfs(int d, int sx, int sy, vector<string> grid){
    int h = grid.size();
    int w = grid[0].size();
    queue<pair<int, int>> q; q.push({sx, sy});
    vector<vector<int>> dist(h, vector<int>(w));
    vector<vector<bool>> visited(h, vector<bool>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            dist[i][j] = -1;
            visited[i][j] = false;
        }
    }
    visited[sx][sy] = true;
    dist[sx][sy] = 0;

    vector<int> dx = {1, 0, 0, -1, 1, 1, -1, -1};
    vector<int> dy = {0, 1, -1, 0, 1, -1, 1, -1};

    while (!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();

        //２方向、４方向、８方向を設定
        for (int i = 0; i < d; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || h-1 < nx) continue;
            if (ny < 0 || w-1 < ny) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == '#') continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
            visited[nx][ny] = true;
        }
        
    }
    return dist;
};

int main() {
    int n; cin >> n;
    vector<vector<int>> ball(n, vector<int>(2));
    rep(i, n) cin >> ball[i][0] >> ball[i][1];

    int ans = n;
    rep(i, n){
        rep(j, n){
            if (i == j) continue;
            lint p = ball[i][0] - ball[j][0];
            lint q = ball[i][1] - ball[j][1];
            int cnt = 0;
            rep(k, n){
                rep(l, n){
                    if (k == l) continue;
                    lint s = ball[k][0] - ball[l][0];
                    lint t = ball[k][1] - ball[l][1];
                    if (p == s && q == t) cnt ++;

                }
            }
            ans = min(ans, n - cnt);
        }
    }
    cout << ans << endl;
}

