#include <stdio.h>
main(){
    int h,w;
    int i,j;
    scanf("%d %d",&h,&w);
    while(h||w){
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                printf((!i||!j||i==h-1||j==w-1) ? "#" : ".");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d",&h,&w);
    }
}