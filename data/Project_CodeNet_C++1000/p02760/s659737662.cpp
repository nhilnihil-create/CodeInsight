#include<iostream>
using namespace std;

int main() {
    int a[3][3];
    int bingo[3][3] = {};
    int n, b;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) if (a[i][j] == b) bingo[i][j] = 1;
        }
    }

    int yes = 0;
    for(int i = 0; i < 3; i++) {
        if (bingo[i][0] && bingo[i][1] && bingo[i][2]) yes = 1;
        if (bingo[0][i] && bingo[1][i] && bingo[2][i]) yes = 1;
    }
    if (bingo[0][0] && bingo[1][1] && bingo[2][2]) yes = 1;
    if (bingo[0][2] && bingo[1][1] && bingo[2][0]) yes = 1;

    if (yes) cout << "Yes" << endl;
    else cout << "No" << endl;

}