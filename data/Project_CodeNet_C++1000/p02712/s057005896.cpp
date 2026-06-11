#include <stdio.h>

int main(){
    int n;
    long long int hasil = 0;
    
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        if(i%3==0){
        
        }
        else if(i%5==0){
    
        }
        else{
            hasil+= i;
        }

    }
    printf("%lld", hasil);
    
    return 0;
}