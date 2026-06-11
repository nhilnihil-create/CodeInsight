#include <stdio.h>
int main(){
    int H[300], W[300], i, j, k;
    for (i=0; i<300; i++){
        scanf("%d%d", &H[i], &W[i]);
        if (H[i] == 0 && W[i] == 0){
            break;
        }
    }
    for (i=0; i<300; i++){
        if (H[i] == 0 && W[i] == 0){
            break;
        }
        for (k=0; k<H[i]; k++){
            for (j = 0; j < W[i]; j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}