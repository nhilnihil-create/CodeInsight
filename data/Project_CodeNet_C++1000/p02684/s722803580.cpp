#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;
    int logK = 0;
    while ((1ll << logK) <= K) logK++;
    vector<vector<int>> exp_next(logK, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        cin >> exp_next[0][i];
        exp_next[0][i]--;
    }
    for (int i = 1; i < logK; ++i) {
        for (int j = 0; j < N; ++j) {
            exp_next[i][j] = exp_next[i - 1][exp_next[i - 1][j]];
        }
    }

    int now = 0;
    for (int i = 0; i < logK; ++i) {
        if ((1ll << i) & K) now = exp_next[i][now];
    }

    cout << ++now << endl;
}