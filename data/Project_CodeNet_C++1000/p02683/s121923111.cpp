//
// Created by 10295 on 27/09/2020.
//

#include <iostream>

using namespace std;
int N;
int M;
int X;
int a[20][20], cost[20], col[20], b[20];
int sum = 1 << 29;
int total;
int kk;

void dfs(int s) {
    if (s == kk + 1) {
        for (int i = 1; i <= M; i++)
            col[i] = 0;
        for (int i = 1; i <= kk; i++)
            for (int j = 1; j <= M; j++) {
                col[j] += a[b[i]][j];
            }
        for (int k = 1; k <= M; ++k) {
            if (col[k] < X) return;
        }
        total = 0;
        for (int j = 1; j <= kk; ++j) total += cost[b[j]];
        sum = min(sum, total);
        return;
    }
    for (int i = b[s - 1] + 1; i <= N; i++) {
        b[s] = i;
        dfs(s + 1);
    }
}

int main() {
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        for (int j = 1; j <= M; ++j)
            cin >> a[i][j];
    }
    for (kk = 1; kk <= N; ++kk) {
        b[0] = 0;
        dfs(1);
    }
    if (sum == 1 << 29)
        cout << "-1" << endl;
    else cout << sum << endl;
    return 0;
}