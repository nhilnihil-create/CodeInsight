#include <iostream>
#include <stdio.h>
using namespace std;
int main(void){
    // Your code here!
    int H,W;
    scanf("%d %d",&H,&W);
    for (int k=0;k<10000;k++){
    if (H==0 && W==0){
        break;
    }
    else{
        for (int i=0;i<=H-1;i++){
            for (int j=0;j<=W-1;j++){
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
        scanf("%d %d",&H,&W);
    }
}
return 0;
}

