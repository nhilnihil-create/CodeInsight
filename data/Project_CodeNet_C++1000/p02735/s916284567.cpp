#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char g[110][110];
int ans[110][110];
int main() {
    int i, j, k;
    int n, t, m;
    int r, c;
    cin >> r >> c;
    for(i = 0; i < r; i++) {
        scanf("%s", &g[i]);
    }
    memset(ans, 0x3f, sizeof(ans));
    ans[0][0] = (g[0][0] == '#');
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(i-1 >= 0) {
                int tmp = ans[i-1][j];
                if(g[i][j] == '#' && g[i-1][j] != '#') tmp++;
                ans[i][j] = min(ans[i][j], tmp);
            }
            if(j-1 >= 0) {
                int tmp = ans[i][j-1];
                if(g[i][j] == '#' && g[i][j-1] != '#') tmp++;
                ans[i][j] = min(ans[i][j], tmp);
            }
        }
    }
    printf("%d\n", ans[r-1][c-1]);
    return 0;
}
