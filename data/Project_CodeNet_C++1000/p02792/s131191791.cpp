#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    int c[10][10];
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; ++i){
        int x = i;
        int res = x % 10;
        while(x >= 10) x /= 10;
        c[res][x]++;
    }
    int ans = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            ans += c[i][j] * c[j][i];
        }
    }
    printf("%d\n", ans);
}