#include <stdio.h>
#define maxn 200010
char s[maxn];
int main() {
    int n, l, r, cnt;
    scanf("%d%s", &n, s + 1);
    l = 1, r = n, cnt = 0;
    while (l < r) {
        while (s[l] == 'R')l++;
        while (s[r] == 'W')r--;
        if (l < r)cnt++,l++,r--;
    }
    printf("%d\n", cnt);
    return 0;
}