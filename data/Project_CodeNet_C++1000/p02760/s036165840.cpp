#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> bingo(3, vector<int>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> bingo[i][j];
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int b;
        cin >> b;
        for (int j = 0; j < 3; j++) {
            replace(bingo.at(j).begin(), bingo.at(j).end(), b, -1);
        }
    }
    bool isb = false;
    if ((bingo[0][0] == -1) && (
        (bingo[0][1] == -1 && bingo[0][2] == -1) ||
        (bingo[1][0] == -1 && bingo[2][0] == -1) ||
        (bingo[1][1] == -1 && bingo[2][2] == -1))) {
        isb = true;
    } else if ((bingo[1][1] == -1) && (  
        (bingo[0][1] == -1 && bingo[2][1] == -1) ||
        (bingo[1][0] == -1 && bingo[1][2] == -1) ||
        (bingo[0][2] == -1 && bingo[2][0] == -1))) {
        isb = true;
    } else if ((bingo[2][2] == -1) && (
        (bingo[2][0] == -1 && bingo[2][1] == -1) ||
        (bingo[0][2] == -1 && bingo[1][2] == -1))) {
        isb = true;
    }
    cout << (isb ? "Yes" : "No") << endl;
}
