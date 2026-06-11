#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main() {
    int h, w, i, j, k, count, x, y, nx, ny;
    char c;
    char map_[100][100];
    queue<pair<int, int> > q;

    while (true) {
        cin >> h >> w;
        if (h==0 && w==0) {
            break;
        }
        for (i=0; i<h; i++) {
            getchar();
            for (j=0; j<w; j++) {
                map_[i][j] = getchar();
            }
        }
        count = 0;
        for (i=0; i<h; i++) {
            for (j=0; j<w; j++) {
                if (map_[i][j] == 'x') {
                    continue;
                }
                count++;
                q.push(make_pair(i, j));
                c = map_[i][j];
                map_[i][j] = 'x';
                while (q.size() > 0) {
                    x = q.front().first;
                    y = q.front().second;
                    q.pop();
                    for (k=0; k<4; k++) {
                        nx = x+dx[k];
                        ny = y+dy[k];
                        if (nx<0 || ny<0 || nx>=h || ny>=w) {
                            continue;
                        }
                        if (map_[nx][ny] == c) {
                            q.push(make_pair(nx, ny));
                            map_[nx][ny] = 'x';
                        }
                    }
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}