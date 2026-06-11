#include <stdio.h>
#include <algorithm>
using namespace std;
char s[4010];
int a[3][4010], b[4010];
int main() {
    int n, i, j, k;
    long long ans = 0;
    scanf("%d%s", &n, s);
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == 'R') b[i] = 0;
        if (s[i] == 'G') b[i] = 1;
        if (s[i] == 'B') b[i] = 2;
        for (j = 0; j < 3; j++) a[j][i] = a[j][i + 1];
        a[b[i]][i]++;
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (b[i] == b[j]) continue;
            int x = 3 - b[i] - b[j];
            ans += a[x][j+1];
            if (j+j-i < n && b[j+j-i]==x) ans--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
