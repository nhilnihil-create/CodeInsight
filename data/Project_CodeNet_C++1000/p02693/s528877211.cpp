#include <stdio.h>


int main(){
    int multi; // 5
    int multiAfter=0;
    int tbawah, tatas; // 14 16
    scanf("%d", &multi);
    scanf("%d %d", &tbawah, &tatas);
    while(multiAfter<=tatas){
        multiAfter=multiAfter+multi;
        if(multiAfter>=tbawah && multiAfter<=tatas){
            printf("OK\n");
            break;
        }
        else if(multiAfter>=tatas){
            printf("NG\n");
            break;
        }    
        else{
            continue;
        }
    }

    return 0;
}