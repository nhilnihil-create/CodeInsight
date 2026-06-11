#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> testimony(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        for (int j = 0; j < A; j++) {
            int x, y;
            cin >> x >> y;
            testimony[i][x - 1] = y;
        }
    }

    int output = 0;
    for (int i = 0; i < (1 << N); i++) {
        bitset<15> bs(i);
        int honest = 0;
        for (int j = 0; j < N; j++) {
            if (!bs[j]) continue;
            honest++;
            for (int k = 0; k < N; k++) {
                if (testimony[j][k] == 1 && !bs[k]) {
                    honest = -1e9;
                    goto loop_exit;
                }
                if (testimony[j][k] == 0 && bs[k]) {
                    honest = -1e9;
                    goto loop_exit;
                }
            }
        }
    loop_exit:
        if (honest > output) output = honest;
    }

    cout << output << endl;

    return 0;
}
