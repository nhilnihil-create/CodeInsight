#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define rep(i,a) for(int i=0;i<(a);++i)
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

int w, h;
int field[51][51];
int dx[] = { -1, -1, -1, 0, 1, 1, 1,  0};
int dy[] = { -1,  0,  1, 1, 1, 0, -1, -1};

bool infield(int x, int y)
{
    return x >= 1 && x <= w && y >= 1 && y <= h;
}

int bfs(int sx, int sy)
{
    queue<P> que;
    que.push(P(sx, sy));
    while(!que.empty()) {
        P p = que.front(); que.pop();
        int x = p.first, y = p.second;
        if(!infield(x, y) || field[y][x] == 0)
            continue;

        field[y][x] = 0;
        for(int i = 0; i < 8; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            que.push(P(nx, ny));
        }
    }
}

int main()
{
    while(cin >> w >> h && w && h) {
        for(int i = 1; i <= h; i++) 
            for(int j = 1; j <= w; j++) 
                cin >> field[i][j];

        int ans = 0;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                if(field[i][j] == 1) { 
                    bfs(j, i);
                    ans++;
                }
            }
        }

        cout << ans << endl;
    }
}