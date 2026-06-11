#include <iostream>

using namespace std;

int w, h;
char map_[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int fill(int x, int y) {
    int count = 1;
    map_[x][y] = '#';
    for (int i=0; i<4; i++) {
        int x_new = x+dx[i];
        int y_new = y+dy[i];
        if (0 <= x_new && x_new < w && 0 <= y_new && y_new < h) {
            if (map_[x_new][y_new] == '.') {
                count += fill(x_new, y_new);
            }
        }
    }
    return count;
}

int main() {
    int x_start, y_start;
    while (true) {
        cin >> w >> h;
        if (w == 0) {
            break;
        }
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> map_[j][i];
                if (map_[j][i] == '@') {
                    x_start = j;
                    y_start = i;
                }
            }
            cin.ignore(1);
        }
        cout << fill(x_start, y_start) << endl;
    }
    return 0;
}