#include <stdio.h>

int main(void){
    int w,h;

    scanf("%d %d", &h, &w);
    while (w!=0 || h!=0){
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if (i>0 && i<h-1 && j>0 && j<w-1) printf(".");
                else printf("#");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d", &h, &w);
    }
    return 0;
}