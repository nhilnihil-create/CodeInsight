#include<stdio.h>
int main(){
    int W,H,x,y,z;
    scanf("%d%d%d%d%d",&W,&H,&x,&y,&z);
    if (0>(x-z) || W<(x+z)){
    printf("No\n");
    }else if(0>(y-z) || H<(y+z) ){
    printf("No\n");
    }else{
    printf("Yes\n");
    }
return 0;
}