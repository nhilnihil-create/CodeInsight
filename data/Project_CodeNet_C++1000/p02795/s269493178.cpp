#include <stdio.h>

int main (){

    int G, N, D;
    scanf("%d %d %d", &G, &N, &D);

    int tot;

    if(G>=N) {
        if(D%G == 0) {
            tot = D/G;
        } else {
            tot = D/G+1;
        }
    } else {
        if(D%N == 0) {
            tot = D/N;
        } else {
            tot = D/N+1;
        }
    }
    printf("%d", tot);

    return 0;
}