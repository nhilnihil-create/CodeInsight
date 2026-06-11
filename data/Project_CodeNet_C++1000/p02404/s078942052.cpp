#include<stdio.h>

int main(){
    int h,w;
    while(scanf("%d %d",&h,&w) && (h != 0 || w != 0)){
        for(int i=0;i < h;i++){
            printf("#");
            for(int j=0;j < w -2 ;j++){
                if(i == 0 || i == h-1){
                    printf("#");
                } else{
                    printf(".");
                }
            }
            printf("#\n");
        }
        printf("\n");
    }
    return 0;
}

