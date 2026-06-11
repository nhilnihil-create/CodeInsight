#include <iostream>
using namespace std;

const int ofst[][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int H, W;
string field[100];

void leveling(int x, int y, const char kind) {
    field[y][x] = '.';
    for (int i = 0; i < 4; i++) {
        int px = x + ofst[i][0];
        int py = y + ofst[i][1];
        if (px < 0 || W <= px || py < 0 || H <= py) continue;
        if (field[py][px] != kind) continue;
        leveling(px, py, kind);
    }
}

int main() {

    while (cin >> H >> W, H) {
        for (int i = 0; i < H; i++) {
            cin >> field[i];
        }

        int count = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (field[i][j] != '.') {
                    leveling(j, i, field[i][j]);
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}