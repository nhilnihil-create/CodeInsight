#include <stdio.h>

int main(void)
{
    int H,W;
    while(H!=0 || W!=0){
        scanf("%d",&H);
        scanf("%d",&W);
        if(H!=0 || W!=0){
            for(int a = 0;a < H;a++){    
                for(int b = 0;b < W;b++){
                    if(a == 0 || a == H-1){
                        printf("#");
                    }else if(b == 0 || b == W-1){
                        printf("#");
                    }else{
                        printf(".");
                    }
                }
                printf("\n");
            }
            printf("\n");
        }else{
        break;
        } 
    }          
    return 0;
}