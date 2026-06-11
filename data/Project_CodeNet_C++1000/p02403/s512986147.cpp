#include <stdio.h>

int main(){
    int H, W;
    scanf("%d%d", &H, &W);
    while(!(H == 0 && W == 0)){
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d%d", &H, &W);
    }
    return 0;
}