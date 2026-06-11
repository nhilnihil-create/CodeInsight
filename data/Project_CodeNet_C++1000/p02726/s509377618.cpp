#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<vector<int>> rou(N, vector<int>(N));
    map<int, int> route;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (i + 1 <= X && j + 1 >= Y) {
                route[j - i - (Y - X - 1)]++;
                rou[i][j] = j - i - (Y - X - 1);
            } else {
                rou[i][j] = min(j - i, abs(X - i - 1) + 1 + abs(Y - j - 1));
                route[rou[i][j]]++;
            }
            // cout << i + 1 << " " << j + 1 << " " << rou[i][j] << endl;
        }
    }

    for (int i = 1; i < N; i++) {
        cout << route[i] << endl;
    }

    return 0;
}
