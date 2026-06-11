#include<stdio.h>

int main(){
    int n,b,f,r,v;
    int houses[4][3][10];
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<10;k++){
                houses[i][j][k] = 0;
            }
        }
    }
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d %d %d %d",&b,&f,&r,&v);
        houses[b-1][f-1][r-1] += v;
    }
    
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<10;k++){
                    printf(" %d",houses[i][j][k]);
            }
            printf("\n");
        }
        if(i != 3) 
            printf("####################\n");
   
    }
    
}



