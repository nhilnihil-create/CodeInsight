#include <stdio.h>

int main(){
    int H, W, N;
    scanf("%d", &H);
    scanf("%d", &W);
    scanf("%d", &N);
    int temp1 = 0;
    int temp2 = 0;
    int ctr1 = 0;
    int ctr2 = 0;
    for(int i =0; i < H; i ++){
        ctr1++;
        temp1+=W;
        if (temp1 >= N){
            break;
        }
    }    
    for(int i =0; i < W; i ++){
        ctr2++;
        temp2+=H;
        if (temp2 >= N){
            break;
        }
    }    
    if(ctr1 < ctr2){
        printf("%d\n", ctr1);
    }else{
        printf("%d\n", ctr2);
    }
    
    return 0;
}