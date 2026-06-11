#include <stdio.h>
int main(void){
    int a, i, OK, NG;
    int A[1000];
    scanf("%d", &a);
    for(i = 0; i < a; i++){
        scanf("%d", &A[i]);
    }
    OK = 0;
    NG = 1;
    for(i = 0; i < a; i++){
        if(A[i]%2 == 0){
            if(A[i]%3 == 0 || A[i]%5 == 0){
                //OK = OK + 1;
            }else{
                NG = NG - 1;
            }
                
        }
         
    }
    if(NG > 0){
        printf("APPROVED");
    }else{
        printf("DENIED");
    }
}
