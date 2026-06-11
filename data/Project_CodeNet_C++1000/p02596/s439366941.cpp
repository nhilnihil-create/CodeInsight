#include <bits/stdc++.h>

using namespace std;

bool vis[1000005];

int main() {
    int k;
    scanf("%d", &k);

    int cur = 0;
    int cnt = 0;

    while (true) {
        cnt++;
        cur = cur * 10 + 7;
        cur %= k;

        if (vis[cur]) return 0 * printf("-1\n");
        vis[cur] = 1;

        if (cur == 0) return 0 * printf("%d\n", cnt);
    }
}
