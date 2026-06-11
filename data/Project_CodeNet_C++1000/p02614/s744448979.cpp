#include<iostream>
using namespace std;
const int BUF = 6;


int row, col, nRemain;
string b[BUF];

void read() {
    cin >> row >> col >> nRemain;
    for (int i = 0; i < row; ++i) {
        cin >> b[i];
    }
}


void work() {
    int ans = 0;
    for (int rMask = 0; rMask < (1 << row); ++rMask) {
        for (int cMask = 0; cMask < (1 << col); ++cMask) {
            int cnt = 0;
            for (int r = 0; r < row; ++r) {
                if (rMask & (1 << r)) continue;
                for (int c = 0; c < col; ++c) {
                    if (cMask & (1 << c)) continue;
                    if (b[r][c] == '.') continue;
                    ++cnt;
                }
            }
            ans += cnt == nRemain;
        }
    }
    cout << ans << endl;
}


int main() {
    read();
    work();
    return 0;
}
