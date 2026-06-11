#include <stdio.h>

int main(void){
    int w,h;

    scanf("%d %d", &h, &w);
    while (w!=0 || h!=0){
        for (int i=0; i<h; i++){
            for (int j=0; j<w; j++){
                if ((i+j) % 2 == 0) printf("#");
                else printf(".");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d", &h, &w);
    }
    return 0;
}