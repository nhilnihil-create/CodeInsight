#include <stdio.h>

int main(){
    
    
    long long num[100000];
    long long c;
    scanf("%lld", &c);
    for(long long i=0;i <c;i++){
        scanf("%lld", &num[i]); 
    }
    for(long long i=0;i < c;i++){
        if(num[i] == 0){ 
            printf("0\n");
            return 0;
        }
    }
    long long int sum = 1;
    for(int i=0;i<c;i++){
        if(num[i] <= 1000000000000000000/sum){
            sum *= num[i];
        }else{
            printf("-1\n");
               return 0;
        }        
    }    printf("%lld\n", sum);
        return 0;    
}