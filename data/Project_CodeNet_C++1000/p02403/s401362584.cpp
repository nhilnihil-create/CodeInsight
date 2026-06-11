#include<stdio.h>

int main(){
    int h,w;
    while(scanf("%d %d",&h,&w) && (h != 0 || w != 0)){
        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
