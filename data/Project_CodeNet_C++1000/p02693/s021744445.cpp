#include <stdio.h>

int main (){


    int z,x,y;
    int flag = 0;
    scanf("%d", &z);
    scanf("%d %d", &x, &y);

    for(int i=x; i<=y; i++){
        if(i%z==0){
          flag = 1;
        }
    }
    if(flag == 1){
        printf("OK\n");
    } else {
        printf("NG\n");
    }
        return 0;
}