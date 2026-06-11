#include <stdio.h>

int main()
{
    int op;

    scanf("%d", &op);


    if (op/100 == 7 || op%100/10 == 7 || op%10 == 7){
        printf("Yes");
    }else{
        printf("No");

    }


    return 0;
}
