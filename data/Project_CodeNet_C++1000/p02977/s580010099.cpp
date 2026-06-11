#include <stdio.h>

int main(void){
    int n; scanf("%d", &n);
    int p = 1; while(p < n) p <<= 1;
    if(p == n){puts("No");}
    else{
        puts("Yes");
        puts("1 2");
        puts("2 3");
        printf("1 %d\n", n+3);
        printf("%d %d\n", n+3, n+2);
        printf("%d %d\n", n+2, n+1);
        int edge = (n % 2 == 0) ? n - 2 : n;
        for(int v = 4; v <= edge; v += 2){
            printf("1 %d\n", v);
            printf("%d %d\n", v, v+1);
            printf("1 %d\n", v+n+1);
            printf("%d %d\n", v+n+1, v+n);
        }
        
        if(n % 2 == 0){
            printf("%d %d\n", n, p >> 1);
            int d = n - (p >> 1) + 1;
            printf("%d %d\n", d + n, 2 * n);
        }
        
    }
    return 0;
}