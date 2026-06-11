#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    scanf("%d", &a);
    scanf("%d", &b);

    if(a==1 && b==2){
        printf("3\n");
    }
    else if(a==2 && b==3){
        printf("1\n");
    }
    else if(a==1 && b==3){
        printf("2\n");
    }
    else if(a==2 && b==1){
        printf("3\n");
    }
    else if(a==3 && b==2){
        printf("1\n");
    }
    else if(a==3 && b==1){
        printf("2\n");
    }

    return 0;
}
