#include <bits/stdc++.h>
using namespace std;

int m, d;

int main() {
	scanf("%d %d", &m, &d);
    int ans = 0;
    for (int i = 1; i <= m; i ++) {
        for (int j = 10; j <= d; j ++) {
            int f = j / 10, s = j % 10;
            if (f < 2 || s < 2) continue;
            if (f * s == i) ans ++;
        }
    }
    printf("%d\n", ans);
	return 0;
}
