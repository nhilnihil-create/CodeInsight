#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXW = 10010;
int N, W;
int C[110][MAXW];
int v[110];
int w[110];

int main() {
    scanf("%d %d", &N, &W);
    memset(C, 0, sizeof(C));
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &v[i], &w[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j >= w[i]) C[i][j] = max(C[i-1][j], C[i-1][j-w[i]] + v[i]);
            else C[i][j] = C[i-1][j];
        }
    }
    printf("%d\n", C[N][W]);
    return 0;
}