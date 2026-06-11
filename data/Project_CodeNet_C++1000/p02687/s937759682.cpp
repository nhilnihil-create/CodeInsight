#include <stdio.h>

int main(){

    char contest[100]="ABC";
    char conbest[100];
    scanf("%s", conbest);
    if (conbest[1]==contest[1]){
        printf("ARC\n");
    }
    else{
        printf("ABC\n");
    }

    return 0;
}