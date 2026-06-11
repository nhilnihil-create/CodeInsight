#include<stdio.h>

int main (){
    int K,A,B;
    int sum=0;
    
    scanf("%d",&K);
    scanf("%d %d", &A, &B);
    
    while (sum < B){
        sum += K;
        if (sum >= A){
            break;
        }
    }
    sum > B ? printf("NG\n") : printf("OK\n");
    //condition ? statement T : statement F   
        
    
    return 0;
}