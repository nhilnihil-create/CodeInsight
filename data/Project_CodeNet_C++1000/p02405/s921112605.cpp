#include <stdio.h>
int main(){
    int h,w;
    int i,j;
    scanf("%d %d",&h,&w);
    while(h||w){
        for(i=0;i<h;i++){
            for(j=0;j<w;j++){
                printf((i+j)%2? "." : "#");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d",&h,&w);
    }
}