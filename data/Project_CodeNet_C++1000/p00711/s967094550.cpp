#include <map>
#include <set>
#include <list>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define fr first
#define sc second
#define mp make_pair

typedef long long int64;
typedef pair< int, int > iP;
typedef pair< iP, int > iiP;

const int INF = 2 << 28;
const double EPS = 1e-10;

int H, W;
char mas[21][21];

int dfs(int x, int y) {
    static int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    int ret = 1;
    mas[y][x] = '#';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(0 <= nx && nx < W && 0 <= ny && ny < H && mas[ny][nx] == '.') {
            ret += dfs(nx, ny);
        }
    }
    return ret;
}

int main() {

    while(cin >> W >> H, W) {

        int sx, sy;
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> mas[i][j];
                if(mas[i][j] == '@') sx = j, sy = i;
            }
        }
        cout << dfs(sx, sy) << endl;
    }
}