#include <stdio.h>

int main(){
    
    int number,ctr;
    scanf("%d", &number);
    if(number <100 || number >999){
        return 1;
    }
    ctr = number;
    for(int i = number; i != 0; i / 10){
        if(ctr % 10 == 7){
            printf("Yes\n");
            break;
        } else {
            ctr /= 10;
            if ( ctr == 0){
             printf("No\n");
             break;
        }
        }
    }
    return 0;
}