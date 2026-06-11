#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int main() {
    int r, c;
    cin >> r >> c;
    int myTable[r + 1][c + 1] = {};

    REP(i, r) {
        REP(j, c) cin >> myTable[i][j];
    }

    REP(i, r) {
        REP(j, c) {
            myTable[i][c] += myTable[i][j];
            myTable[r][j] += myTable[i][j];
            myTable[r][c] += myTable[i][j];
        }
    }

    REP(i, r+1) {
        REP(j, c+1) {
            if (j) cout << " ";
            cout << myTable[i][j];
        }
        cout << endl;
    }
}