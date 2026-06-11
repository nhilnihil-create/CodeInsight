#include <stdio.h>

int main()
{
    int L, R, d, ans = 0;

    scanf("%d %d %d", &L, &R, &d);

    while (L <= R){
        if (L%d == 0){
            ans++;
            L++;
            continue;
        }else{
        L++;
        continue;
        }

    }

    printf("%d", ans);



    return 0;
}
