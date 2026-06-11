#include<stdio.h>
int main(){
    int H[10000], W[10000];
    int length;
    int i=0, j, k;
    do{
        scanf("%d %d", &H[i], &W[i]);
        i += 1;
    }while(H[i-1]!=0 || W[i-1]!=0);
    length = i;
    for(i=0; i<length-1; i++){
        for(j=0; j<H[i]; j++){
            for(k=0; k<W[i]; k++){
                if(j==0 || j==H[i]-1 || k==0 || k==W[i]-1){
                    printf("#");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}