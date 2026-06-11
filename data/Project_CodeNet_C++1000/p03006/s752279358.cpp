#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<vector<int>> XY(N, vector<int>(2));
    for (int i = 0; i < N; i++) {
        cin >> XY[i][0] >> XY[i][1];
    }
    sort(XY.begin(), XY.end(), [](auto& x, auto& y) { return x[0] > y[0]; });
    sort(XY.begin(), XY.end(), [](auto& x, auto& y) { return x[1] > y[1]; });
    int match = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            int m = 0, p, q;
            p = XY[i][0] - XY[j][0];
            q = XY[i][1] - XY[j][1];
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < N; l++) {
                    if (k == l) continue;
                    if (XY[k][0] - XY[l][0] == p && XY[k][1] - XY[l][1] == q) m++;
                }
            }
            match = max(m, match);
        }
    }
    cout << N - match << endl;
}