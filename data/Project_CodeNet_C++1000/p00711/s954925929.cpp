#include <iostream>
#include <string>
using namespace std;

char map[20][20];
int visited[20][20];

void dfs(int x, int y, int w, int h) {
    visited[x][y] = 1;
    for (int i = -1; i <= 1; i += 2) {
        if (0 <= x+i && x+i < h && visited[x+i][y] == 0 && map[x+i][y] == '.')
            dfs(x+i, y, w, h);
    }
    for (int i = -1; i <= 1; i += 2) {
        if (0 <= y+i && y+i < w && visited[x][y+i] == 0 && map[x][y+i] == '.')
            dfs(x, y+i, w, h);
    }
}

int main(int argc, char *argv[])
{
    int w, h, x, y, sum;
    string line;
    while (cin >> w >> h, w | h) {
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                visited[i][j] = 0;
        for (int i = 0; i < h; ++i) {
            cin >> line;
            for (int j = 0; j < w; ++j) {
                map[i][j] = line[j];
                if (line[j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y, w, h);
        sum = 0;
        for (int i = 0; i < 20; ++i)
            for (int j = 0; j < 20; ++j)
                sum += visited[i][j];
        cout << sum << endl;
    }
    return 0;
}