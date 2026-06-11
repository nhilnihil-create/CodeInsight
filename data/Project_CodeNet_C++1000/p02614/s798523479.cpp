#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

vector<string> board;
int H, W, K;
void func(int &su, int num, vector<bool> row, vector<bool> column) {
    if (num == H + W) {
        int cnt = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (row[i] == 1) continue;
                if (column[j] == 1) continue;
                if (board[i][j] == '#') cnt++;
            }
        }
        if (cnt == K) su++;
        return;
    }

    if (num < H) {
        func(su, num + 1, row, column);
        row[num] = 1;
        func(su, num + 1, row, column);
    }
    else {
        func(su, num + 1, row, column);
        column[num - H] = 1;
        func(su, num + 1, row, column);
    }
    return;
}

int main() {
    cin >> H >> W >> K;
    board.resize(H);
    for (int i = 0; i < H; i++) cin >> board[i];
    int su = 0, num = 0;
    vector<bool> row(H, 0), column(W, 0);
    func(su, num, row, column);
    cout << su << endl;
}