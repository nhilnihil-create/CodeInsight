#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> Bingo(3, vector<int>(3));

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> Bingo.at(i).at(j);
    }

    int N, S;
    cin >> N;
    vector<int> Bi(N);
    for(int i = 0; i < N; i++) {
        cin >> Bi.at(i);
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < N; k++) {
                if (Bingo.at(i).at(j) == Bi.at(k)) Bingo.at(i).at(j) = 0;
            }
        }
    }

    bool ans = false;
    for (int i = 0; i < 3; i++) {
        if (Bingo.at(i).at(0) == 0 && Bingo.at(i).at(1) == 0 && Bingo.at(i).at(2) == 0) ans = true;
        if (Bingo.at(0).at(i) == 0 && Bingo.at(1).at(i) == 0 && Bingo.at(2).at(i) == 0) ans = true;
    }
    if (Bingo.at(0).at(0) == 0 && Bingo.at(1).at(1) == 0 && Bingo.at(2).at(2) == 0) ans = true;
    else if (Bingo.at(0).at(2) == 0 && Bingo.at(1).at(1) == 0 && Bingo.at(2).at(0) == 0) {ans = true;}

    cout << (ans ? "Yes" : "No") << endl;
}