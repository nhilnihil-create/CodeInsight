#include <cstdio>

int main()
{
    int i,n,x;
    int a[3];

    while(1){
        i = 0;
        scanf("%d %d", &n, &x);
        if(n == 0 && x == 0) break;
        for(int k = 1; k <= n - 2; k++){
            for(int l = k + 1; l <= n - 1; l++){
                for(int m = l + 1; m <= n; m++){
                    a[0] = k;
                    a[1] = l;
                    a[2] = m;
                    if(x == a[0] + a[1] + a[2]) i++;
                }
            }
        }
        printf("%d\n", i);
    }
    return 0;
}