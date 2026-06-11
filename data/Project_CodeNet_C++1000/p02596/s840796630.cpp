#include <bits/stdc++.h>

int main(){
    int k;
    scanf("%d", &k);
    int cur = 0;
    for (int i = 0; i < 2000000; ++ i){
        cur = (10 * cur + 7) % k;
        if (cur == 0){
            printf("%d\n", i + 1);
            return 0;
        }
    }
    puts("-1");
    return 0;
}