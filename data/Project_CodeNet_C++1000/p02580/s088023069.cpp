#include <stdio.h>
#include <queue>
using namespace std;
int Col[300000], Row[300000];
int main() {
    int n, m, k, x, y;
    scanf("%i%i%i", &n, &m, &k);
    queue<pair<int, int>> Enemies;
    for (int i = 0; i < k; i++) {
        scanf("%i%i", &x, &y);
        x--, y--;
        Row[x]++, Col[y]++;
        Enemies.push(make_pair(x, y));
    }


    int maxCol = Col[0], maxRow = Row[0],
        n_maxRow = 0, n_maxCol = 0;
    for (int i = 1; i < n; i++) {
        if (maxRow < Row[i])
            maxRow = Row[i];
    }
    for (int i = 1; i < m; i++) {
        if (maxCol < Col[i])
            maxCol = Col[i];
    }
    for (int i = 0; i < n; i++) {
        if (maxRow == Row[i])
            n_maxRow++;
    }
    for (int i = 0; i < m; i++) {
        if (maxCol == Col[i])
            n_maxCol++;
    }


    int cnt = 0;
    while (!Enemies.empty()) {
        x = Enemies.front().first,
        y = Enemies.front().second;
        Enemies.pop();

        if (Row[x] == maxRow && Col[y] == maxCol) {
            cnt++;
        }
    }

    printf("%i", maxRow + maxCol - (n_maxRow * 1ll * n_maxCol == cnt));
}
