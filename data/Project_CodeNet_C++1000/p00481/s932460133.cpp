#include <iostream>
#include <queue>
#include <string>

#define rep(i, n) for (int i = 0; i < n; i++)

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

using namespace std;
int H, W, N;
char map[1003][1003];
int dist[1003][1003];

int bfs(char s, char t) {
    queue<int> que_x, que_y;
    rep(y, 1003) rep(x, 1003) dist[y][x] = -1;
    rep(y, H) rep(x, W) {
        if (s == map[y][x]) {
            dist[y][x] = 0;
            que_y.push(y);
            que_x.push(x);
        }
    }

    int ret = 0;
    while (que_x.size()) {
        int x = que_x.front();
        int y = que_y.front();
        que_x.pop();
        que_y.pop();
        if (map[y][x] == t) {
            ret = dist[y][x];
            break;
        }
        rep(k, 4) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny < 0 || H <= ny) continue;
            if (nx < 0 || W <= nx) continue;
            if (map[ny][nx] == 'X') continue;
            if (dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            que_x.push(nx);
            que_y.push(ny);
        }
    }
    return ret;
}

void solve() {
    int ans = 0;

    ans += bfs('S', '1');
    rep(i, N - 1) ans += bfs(i + '1', i + '2');
    cout << ans << endl;
}

int main() {
    cin >> H >> W >> N;
    rep(y, H) cin >> map[y];
    solve();
}