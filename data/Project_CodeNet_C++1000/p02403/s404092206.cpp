#include <stdio.h>
int main(void)
{
    int h,w,i,j,k;
    
    do{
        scanf("%d",&h); scanf("%d",&w);
        if(h+w>0){
            for(i=0;i<h;i++){
                for(j=0;j<w;j++){
                    printf("#");
                }
                printf("\n");
            }
            printf("\n");
        }
    }while(w+h>0);
    return(0);
}