#include <stdio.h>

int main (){
    int l, r, d;
    int ang, a = 0;
    scanf("%d %d %d", &l, &r, &d);

    for(int i = 1; i < 101; i++){
        ang = i * d;
        if( ang >= l && ang <= r){
            a++;
        }
    }
    printf("%d", a);
    return 0;
}