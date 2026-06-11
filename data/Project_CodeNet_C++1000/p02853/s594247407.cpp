#include<stdio.h>
int main() {
    int x, y, ans = 0;
    scanf("%d%d", &x, &y);
    if(x == 3) ans += 1;
    if(x == 2) ans += 2;
    if(x == 1) ans += 3;
    if(y == 3) ans += 1;
    if(y == 2) ans += 2;
    if(y == 1) ans += 3;
    if(x == 1 && y == 1) ans += 4;
    printf("%d\n", ans * 100000);
    return 0;
} 