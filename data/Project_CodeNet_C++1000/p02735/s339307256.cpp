#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 114, INF = 1e4;

int N, M, F[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%s", grid[i] + 1);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            F[i][j] = INF;
    F[1][1] = grid[1][1] == '#';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i < N) F[i + 1][j] = min(F[i + 1][j], F[i][j] + (grid[i][j] != grid[i + 1][j]));
            if (j < M) F[i][j + 1] = min(F[i][j + 1], F[i][j] + (grid[i][j] != grid[i][j + 1]));
        }
    }
    printf("%d\n", (F[N][M] + 1) / 2);
}
