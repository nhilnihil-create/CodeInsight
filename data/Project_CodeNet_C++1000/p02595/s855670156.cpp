#include <bits/stdc++.h>

int main(){
    int n, d;
    scanf("%d%d", &n, &d);
    int cnt = 0;
    while (n --){
        int x, y;
        scanf("%d%d", &x, &y);
        if (1ll * x * x + 1ll * y * y <= 1ll * d * d){
            ++ cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}