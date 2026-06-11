#include <stdio.h>
char s[200010];
int c[2020], inv = 202;
int main() {
    int ans = 0, tt = 1, cur = 0;
    scanf("%s", s);
    c[0] = 1;
    for (int i = 0; s[i]; i++) {
        int x = s[i] - '0';
        cur = (cur * 10 + x) % 2019;
        tt = (tt * inv) % 2019;
        ans += c[(cur * tt) % 2019];
        c[(cur * tt) % 2019]++;
    }
    printf("%d\n", ans);
    return 0;
}
