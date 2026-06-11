#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 5;

int h, w, k;
char c[10][10];
int ta[MAXN][10];

int main(int argc, char* argv[]) {
    scanf("%d %d %d", &h, &w, &k);
    for (int i = 0; i < h; i++)
        scanf("%s", c[i]);
    int ans = 0;
    for (int i = 0; i < (1 << 6); i++) {
        int cc = i;
        for (int j = 0; j < 6; j++) {
            if (cc & 1) ta[i][j] = 1;
            cc >>= 1;
        }
    }
    for (int i = 0; i < (1 << h); i++) {
        for (int j = 0; j < (1 << w); j++) {

            int sum = 0;
            for (int x = 0; x < h; x++) {
                if (ta[i][x] == 1) continue;
                for (int y = 0; y < w; y++) {
                    if (ta[j][y] == 1)
                        continue;
                    else if (c[x][y] == '#')
                        sum++;
                }
            }
            if (sum == k) ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
