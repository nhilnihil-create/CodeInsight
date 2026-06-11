#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int y = 1;
    scanf("%d",&x);
    if(360 % x == 0){
        printf("%d",360/x);
    }
    else{
        while((x*y)%360 != 0){
            y++;
        }
        printf("%d",y);
    }
    return 0;
}