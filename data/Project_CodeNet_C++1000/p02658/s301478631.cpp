#include <stdio.h>

int main(){
    long long int t;
    scanf("%lld",&t);
    long long int num[t]={0}; 
    long long int hasil=1;
    for (long long int i=0;i<t;i++){
        scanf("%lld",&num[i]); 
    }
    for(long long int i=0;i<t;i++){
    
        if (num[i]==0){
            printf("0\n");
            return 0;
        }
        }
    for (int i=0;i<t;i++){
        if(num[i]<=1000000000000000000/hasil){
            hasil*=num[i];
        }
        else{
            printf("-1\n");
            return 0;
        }
    }    
        printf("%lld",hasil);
        return 0;
    }